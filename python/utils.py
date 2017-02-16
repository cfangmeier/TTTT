import io
import sys
import itertools as it
from os.path import dirname, join, abspath, normpath
from math import ceil, sqrt
from subprocess import run
from IPython.display import Image

import pydotplus.graphviz as pdp
import ROOT

PRJ_PATH = normpath(join(dirname(abspath(__file__)), "../"))
EXE_PATH = join(PRJ_PATH, "build/main")

PDG = {
        1:   'd',
        -1:  'd̄',
        2:   'u',
        -2:  'ū',
        3:   's',
        -3:  's̄',
        4:   'c',
        -4:  'c̄',
        5:   'b',
        -5:  'b̄',
        6:   't',
        -6:  't̄',
        11:  'e-',
        -11: 'e+',
        12:  'ν_e',
        -12: 'ῡ_e',

        13:  'μ-',
        -13: 'μ+',
        14:  'ν_μ',
        -14: 'ῡ_μ',

        15:  'τ-',
        -15: 'τ+',
        16:  'ν_τ',
        -16: 'ῡ_τ',

        21:  'gluon',
        22:  'γ',
        23:  'Z0',
        24:  'W+',
        -24: 'W-',
        25:  'H',
      }


def show_event(dataset, idx):
    ids = list(dataset.GenPart_pdgId[idx])
    nrgs = list(dataset.GenPart_energy[idx])
    links = list(dataset.GenPart_motherIndex[idx])
    max_nrg = max(nrgs)
    nrgs_scaled = [nrg/max_nrg for nrg in nrgs]
    g = pdp.Dot()
    for i, id_ in enumerate(ids):
        color = ",".join(map(str, [nrgs_scaled[i], .7, .8]))
        g.add_node(pdp.Node(str(i), label=PDG[id_],
                   style="filled",
                   fillcolor=color))
    for i, mother in enumerate(links):
        if mother != -1:
            g.add_edge(pdp.Edge(str(mother), str(i)))
    return Image(g.create_gif())


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
    single_plot_size = (600, 450)
    max_width = 1800

    scale = .75
    x_size = int(1600*scale)
    y_size = int(1200*scale)
    canvas = ROOT.TCanvas("c1", "", x_size, y_size)
    # @property
    # def canvas(self):
    #     cls = self.__class__
    #     if not hasattr(cls, "_canvas"):
    #         scale = .75
    #         x_size = int(1600*scale)
    #         y_size = int(1200*scale)
    #         cls._canvas = ROOT.TCanvas("c1", "", x_size, y_size)
    #     return cls._canvas

    def __init__(self, sample_name, input_filename,
                 rebuild_hists=False):
        self.sample_name = sample_name
        if rebuild_hists:
            run([EXE_PATH, "-s", "-f", input_filename])
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

    def draw(self, shape=None):
        if shape is None:
            n_plots = len([obj for obj in self.map.values() if hasattr(obj, "Draw") ])
            if n_plots*self.single_plot_size[0] > self.max_width:
                shape_x = self.max_width//self.single_plot_size[0]
                shape_y = ceil(n_plots / shape_x)
                shape = (shape_x, shape_y)
        self.canvas.Clear()
        self.canvas.SetCanvasSize(shape[0]*self.single_plot_size[0],
                                  shape[1]*self.single_plot_size[1])
        self.canvas.Divide(*shape)
        i = 1
        for hist in self.map.values():
            self.canvas.cd(i)
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
                # print("cannot draw object", hist)
                continue  # Not a drawable type(probably)
            hist.Draw(draw_option)
            i += 1
        self.canvas.Draw()

    @classmethod
    def get_hist_set(cls, attrname):
        labels, hists = zip(*[(sample_name, getattr(h, attrname))
                              for sample_name, h in cls.collections.items()])
        return labels, hists

    @classmethod
    def add_collection(cls, hc):
        if not hasattr(cls, "collections"):
            cls.collections = {}
        cls.collections[hc.sample_name] = hc

    @classmethod
    def stack_hist(cls,
                   hist_name,
                   title="",
                   enable_fill=False,
                   normalize_to=0,
                   draw=False,
                   draw_canvas=True,
                   draw_option="",
                   make_legend=False,
                   _stacks={}):
        labels, hists = cls.get_hist_set(hist_name)
        if draw_canvas:
            cls.canvas.Clear()
            cls.canvas.SetCanvasSize(cls.single_plot_size[0],
                                      cls.single_plot_size[1])

        colors = it.cycle([ROOT.kRed, ROOT.kBlue, ROOT.kGreen])
        stack = ROOT.THStack(hist_name+"_stack", title)
        if labels is None:
            labels = [hist.GetName() for hist in hists]
        if type(normalize_to) in (int, float):
            normalize_to = [normalize_to]*len(hists)
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
            if make_legend:
                cls.canvas.BuildLegend(0.75, 0.75, 0.95, 0.95, "")
        # prevent stack from getting garbage collected
        _stacks[stack.GetName()] = stack
        if draw_canvas:
            cls.canvas.Draw()
        return stack

    @classmethod
    def stack_hist_array(cls,
                         hist_names,
                         titles,
                         shape=None, **kwargs):
        n_hists = len(hist_names)
        if shape is None:
            if n_hists <= 4:
                shape = (1, n_hists)
            else:
                shape = (ceil(sqrt(n_hists)),)*2
        cls.canvas.SetCanvasSize(cls.single_plot_size[0]*shape[0],
                                  cls.single_plot_size[1]*shape[1])
        cls.canvas.Divide(*shape)
        for i, hist_name, title in zip(bin_range(n_hists), hist_names, titles):
            cls.canvas.cd(i)
            hists, labels = cls.get_hist_set(hist_name)
            cls.stack_hist(hist_name, title=title, draw=True,
                           draw_canvas=False, **kwargs)
        cls.canvas.cd(n_hists).BuildLegend(0.75, 0.75, 0.95, 0.95, "")
