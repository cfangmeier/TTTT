import ROOT


canvas = ROOT.TCanvas("c1")
def do_plots():
    ROOT.lepton_count.Draw()
    canvas.Draw()