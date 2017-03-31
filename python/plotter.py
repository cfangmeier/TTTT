#!/usr/bin/env python3
import matplotlib as mpl
mpl.rc('font', **{'family': 'sans-serif', 'sans-serif': ['Helvetica']})
mpl.rc('font', **{'family': 'serif', 'serif': ['Palatino']})
mpl.rc('text', usetex=True)
mpl.rc('savefig', dpi=120)


class StackHist:

    def __init__(self, title=""):
        self.title = title
        self.xlabel = ""
        self.ylabel = ""
        self.xlim = (None, None)
        self.ylim = (None, None)
        self.logx = False
        self.logy = False
        self.backgrounds = []
        self.signal = None
        self.signal_stack = True
        self.data = None

    @staticmethod
    def to_bin_list(th1, scale=1):
        bins = []
        for i in range(th1.GetNbinsX()):
            center = th1.GetBinCenter(i + 1)
            width = th1.GetBinWidth(i + 1)
            content = th1.GetBinContent(i + 1)
            bins.append((center-width/2, center+width/2, content*scale))
        return bins

    def add_mc_background(self, th1, label, lumi=None):
        self.backgrounds.append((label, lumi, self.to_bin_list(th1)))

    def set_mc_signal(self, th1, label, lumi=None, stack=True, scale=1):
        if scale != 1:
            label = r"{}$\times{:02d}$".format(label, scale)
        self.signal = (label, lumi, self.to_bin_list(th1, scale))
        self.signal_stack = stack

    def set_data(self, th1, lumi=None):
        self.data = ('data', lumi, self.to_bin_list(th1))
        self.luminosity = lumi

    def _verify_binning_match(self):
        bins_count = [len(bins) for label, lumi, bins in self.backgrounds]
        if self.signal is not None:
            bins_count.append(len(self.signal[2]))
        if self.data is not None:
            bins_count.append(len(self.data[2]))
        n_bins = bins_count[0]
        if any(bin_count != n_bins for bin_count in bins_count):
            raise ValueError("all histograms must have the same number of bins")
        return n_bins

    def _add_decorations(self, axes):
        cms_prelim = r'{\raggedright{}\textsf{\textbf{CMS}}\\ \emph{Preliminary}}'
        axes.text(0.01, 0.99, cms_prelim,
                  horizontalalignment='left',
                  verticalalignment='top',
                  transform=axes.transAxes)

        lumi = ""
        energy = ""
        if self.luminosity is not None:
            lumi = r'${} \mathrm{{fb}}^{{-1}}$'.format(self.luminosity)
        if self.energy is not None:
            energy = r'({} TeV)'.format(self.energy)

        axes.text(1, 1, ' '.join([lumi, energy]),
                  horizontalalignment='right',
                  verticalalignment='bottom',
                  transform=axes.transAxes)

    def draw(self, axes):
        n_bins = self._verify_binning_match()
        bottoms = [0]*n_bins

        if self.logx:
            axes.set_xscale('log')
        if self.logy:
            axes.set_yscale('log')

        def draw_bar(label, lumi, bins, stack=True, **kwargs):
            if stack:
                lefts = []
                widths = []
                heights = []
                for left, right, content in bins:
                    lefts.append(left)
                    widths.append(right-left)
                    if lumi is not None:
                        content *= self.luminosity/lumi
                    heights.append(content)

                axes.bar(lefts, heights, widths, bottoms, label=label, **kwargs)
                for i, (_, _, content) in enumerate(bins):
                    if lumi is not None:
                        content *= self.luminosity/lumi
                    bottoms[i] += content
            else:
                xs = [bins[0][0] - (bins[0][1]-bins[0][0])/2]
                ys = [0]
                for left, right, content in bins:
                    width2 = (right-left)/2
                    if lumi is not None:
                        content *= self.luminosity/lumi
                    xs.append(left-width2)
                    ys.append(content)
                    xs.append(right-width2)
                    ys.append(content)
                xs.append(bins[-1][0] + (bins[-1][1]-bins[-1][0])/2)
                ys.append(0)
                axes.plot(xs, ys, label=label, **kwargs)

        if self.signal is not None and self.signal_stack:
            draw_bar(*self.signal, hatch='/')

        for background in self.backgrounds:
            draw_bar(*background)

        if self.signal is not None and not self.signal_stack:
            draw_bar(*self.signal, stack=False, color='k')

        axes.set_title(self.title)
        axes.set_xlabel(self.xlabel)
        axes.set_ylabel(self.ylabel)
        axes.set_xlim(*self.xlim)
        # axes.set_ylim(*self.ylim)
        axes.set_ylim(None, max(bottoms)*1.2)
        axes.legend(frameon=True, ncol=2)
        self._add_decorations(axes)


if __name__ == '__main__':
    import matplotlib.pyplot as plt
    from utils import ResultSet

    rs_TTZ =  ResultSet("TTZ",  "../data/TTZToLLNuNu_treeProducerSusyMultilepton_tree.root")
    rs_TTW  = ResultSet("TTW",  "../data/TTWToLNu_treeProducerSusyMultilepton_tree.root")
    rs_TTH  = ResultSet("TTH", "../data/TTHnobb_mWCutfix_ext1_treeProducerSusyMultilepton_tree.root")
    rs_TTTT = ResultSet("TTTT", "../data/TTTT_ext_treeProducerSusyMultilepton_tree.root")

    sh = StackHist('B-Jet Multiplicity')
    sh.add_mc_background(rs_TTZ.b_jet_count, 'TTZ', lumi=40)
    sh.add_mc_background(rs_TTW.b_jet_count, 'TTW', lumi=40)
    sh.add_mc_background(rs_TTH.b_jet_count, 'TTH', lumi=40)
    sh.set_mc_signal(rs_TTTT.b_jet_count, 'TTTT', lumi=40, scale=10)

    sh.luminosity = 40
    sh.energy = 13
    sh.xlabel = 'B-Jet Count'
    sh.ylabel = r'\# Events'
    sh.xlim = (-.5, 9.5)
    sh.signal_stack = False

    fig = plt.figure()
    sh.draw(fig.gca())
    plt.show()
    # sh.add_data(rs_TTZ.b_jet_count, 'TTZ')
