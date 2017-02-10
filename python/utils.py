import io
import sys
from math import ceil, sqrt
from subprocess import run
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
        sum_ = 0
        for row in bin_range(rows):
            sum_ += hist2d.GetBinContent(col, row)
        if sum_ == 0:
            continue
        for row in bin_range(rows):
            norm = hist2d.GetBinContent(col, row) / sum_
            normHist.SetBinContent(col, row, norm)
    return normHist

class HistCollection:
    def __init__(self, sample_name, input_filename,
                 exe_path="../build/main",
                 rebuild_hists=False):
        self.sample_name = sample_name
        if rebuild_hists:
            run([exe_path, "-s", "-f", input_filename])
        output_filename = input_filename.replace(".root", "_result.root")
        file = ROOT.TFile.Open(output_filename)
        l = file.GetListOfKeys()
        self.map = {}
        for i in range(l.GetSize()):
            name = l.At(i).GetName()
            new_name = ":".join((sample_name, name))
            obj = file.Get(name)
            try:
                obj.SetName(new_name)
                obj.SetDirectory(0)  # disconnects Object from file
            except AttributeError:
                pass
            self.map[name] = obj
            setattr(self, name, obj)
        file.Close()
        # Now add these histograms into the current ROOT directory (in memory)
        # and remove old versions if needed
        for obj in self.map.values():
            try:
                old_obj = ROOT.gDirectory.Get(obj.GetName())
                ROOT.gDirectory.Remove(old_obj)
                ROOT.gDirectory.Add(obj)
            except AttributeError:
                pass
        HistCollection.add_collection(self)

    def draw(self, canvas, shape=None):
        if shape is None:
            n = int(ceil(sqrt(len(self.map))))
            shape = (n, n)
        canvas.Clear()
        canvas.Divide(*shape)
        i = 1
        for hist in self.map.values():
            canvas.cd(i)
            try:
                hist.SetStats(False)
            except AttributeError:
                pass
            draw_option = ""
            if type(hist) in (ROOT.TH1F, ROOT.TH1I, ROOT.TH1D):
                draw_option = ""
            elif type(hist) in (ROOT.TH2F, ROOT.TH2I, ROOT.TH2D):
                draw_option = "COLZ"
            elif type(hist) in (ROOT.TGraph,):
                draw_option = "A*"
            else:
                print("cannot draw object", hist)
                continue  # Not a drawable type(probably)
            hist.Draw(draw_option)
            i += 1

    @classmethod
    def add_collection(cls, hc):
        if not hasattr(cls, "collections"):
            cls.collections = {}
        cls.collections[hc.sample_name] = hc


    @classmethod
    def stack_hist(hists,
                   labels=None, id_=None,
                   title="", enable_fill=False,
                   normalize_to=0, draw=False,
                   draw_option="",
                   _stacks={}):
        """hists should be a list of TH1D objects
        returns a new stacked histogram
        """
        colors = it.cycle([ROOT.kRed, ROOT.kBlue, ROOT.kGreen])
        stack = ROOT.THStack(id_, title)
        if labels is None:
            labels = [hist.GetName() for hist in hists]
        if type(normalize_to) in (int, float):
            normalize_to = [normalize_to]*len(hists)
        if id_ is None:
            id_ = hists[0].GetName() + "_stack"
        ens = enumerate(zip(hists, labels, colors, normalize_to))
        for i, (hist, label, color, norm) in ens:
            hist_copy = hist
            hist_copy = hist.Clone(hist.GetName()+"_clone")
            hist_copy.SetTitle(label)
            if enable_fill:
                hist_copy.SetFillColorAlpha(color, 0.75)
                hist_copy.SetLineColorAlpha(color, 0.75)
            if norm:
                integral = hist_copy.Integral()
                hist_copy.Scale(norm/integral, "nosw2")
                hist_copy.SetStats(False)
            stack.Add(hist_copy)
        if draw:
            stack.Draw(draw_option)
        _stacks[id_] = stack  # prevent stack from getting garbage collected
                              # needed for multipad plots :/
        return stack


    @classmethod
    def stack_hist_array(canvas, histcollections, fields, titles,
                         shape=None, **kwargs):
        def get_hist_set(attrname):
            hists, labels = zip(*[(getattr(h, attrname), h.sample_name)
                                  for h in histcollections])
            return hists, labels
        n_fields = len(fields)
        if shape is None:
            if n_fields <= 4:
                shape = (1, n_fields)
            else:
                shape = (ceil(sqrt(n_fields)),)*2
        canvas.Clear()
        canvas.Divide(*shape)
        for i, field, title in zip(bin_range(n_fields), fields, titles):
            canvas.cd(i)
            hists, labels = get_hist_set(field)
            stack_hist(hists, labels, id_=field, title=title, draw=True, **kwargs)
        canvas.cd(1).BuildLegend(0.75, 0.75, 0.95, 0.95, "")
