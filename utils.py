import io
import sys
import itertools as it
import ROOT

class OutputCapture:
    def __init__(self):
        self.my_stdout = io.StringIO()
        self.my_stderr = io.StringIO()

    def get_stdout(self):
        self.my_stdout.seek(0)
        return self.my_stdout.read()

    def get_stderr(self):
        self.my_stderr.seek(0)
        return self.my_stderr.read()

    def __enter__(self):
        self.stdout = sys.stdout
        self.stderr = sys.stderr
        sys.stdout = self.my_stdout
        sys.stderr = self.my_stderr

    def __exit__(self, *args):
        sys.stdout = self.stdout
        sys.stderr = self.stderr
        self.stdout = None
        self.stderr = None

def bin_range(n, end=None):
    if end is None:
        return range(1, n+1)
    else:
        return range(n+1, end+1)
        
def normalize_columns(hist2d):
    normHist = ROOT.TH2D(hist2d)
    cols, rows = hist2d.GetNbinsX(), hist2d.GetNbinsY()
    for col in bin_range(cols):
        sum_ = 0;
        for row in bin_range(rows):
            sum_ += hist2d.GetBinContent(col, row)
        if sum_ == 0:
            continue
        for row in bin_range(rows):
            norm = hist2d.GetBinContent(col, row) / sum_
            normHist.SetBinContent(col, row, norm)
    return normHist

def stack_hist(hists, labels=None, id_="stack", title="", enable_fill=False, normalize_to=0):
    """hists should be a list of TH1D objects
    returns a new stacked histogram
    """
    colors = it.cycle([ROOT.kRed,ROOT.kBlue, ROOT.kGreen])
    stack = ROOT.THStack(id_, title)
    if labels is None:
        labels = [hist.GetName() for hist in hists]
    for i, (hist, label, color) in enumerate(zip(hists, labels, colors)):
        hist_copy = hist
        hist_copy = hist.Clone(str(i)+"_clone")
        hist_copy.SetTitle(label)
        hist_copy.SetStats(False)
        if enable_fill:
            hist_copy.SetFillColorAlpha(color, 0.75)
            hist_copy.SetLineColorAlpha(color, 0.75)
        if normalize_to:
            integral = hist_copy.Integral()
            hist_copy.Scale(normalize_to/integral, "nosw2")
            hist_copy.SetStats(False)
        stack.Add(hist_copy)
    return stack