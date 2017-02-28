import pydotplus.graphviz as pdp
log = """
"GenPart_eta" at address 0x43f4040
"GenPart_mass" at address 0x43f1110
"GenPart_motherId" at address 0x43f70a0
"GenPart_motherIndex" at address 0x43f88d0
"GenPart_pdgId" at address 0x44cb260
"GenPart_phi" at address 0x43f2810
"GenPart_pt" at address 0x43f5860
"GenPart_status" at address 0x43ef9a0
"Jet_btagCMVA" at address 0x44cd090
"Jet_eta" at address 0x43f0b50
"Jet_mass" at address 0x44cee60
"Jet_phi" at address 0x43eff60
"Jet_pt" at address 0x43f16d0
"LepGood_charge" at address 0x43f6a70
"LepGood_eta" at address 0x43f8f10
"LepGood_mass" at address 0x43f7700
"LepGood_mcMatchAny" at address 0x43f4690
"LepGood_mcMatchId" at address 0x43f5e60
"LepGood_mcMatchPdgId" at address 0x43f5270
"LepGood_mcMatchTau" at address 0x43f3a10
"LepGood_mcPt" at address 0x43f2e80
"LepGood_pdgId" at address 0x44cb8b0
"LepGood_phi" at address 0x43f8290
"LepGood_pt" at address 0x44cac00
"cartProduct(lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass)),lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass)))" at address 0x2c7a230
"count(bJet_Selection:vectorOf(nJet,Jet_btagCMVA))" at address 0x442cbc0
"count(is_electron:vectorOf(nGenPart,GenPart_pdgId))" at address 0x2c7bad0
"count(is_electron:vectorOf(nLepGood,LepGood_pdgId))" at address 0x2c7be30
"count(is_lepton:vectorOf(nGenPart,GenPart_pdgId))" at address 0x2c7bde0
"count(is_lepton:vectorOf(nLepGood,LepGood_pdgId))" at address 0x2c7c230
"count(is_muon:vectorOf(nGenPart,GenPart_pdgId))" at address 0x2c7bb20
"count(is_muon:vectorOf(nLepGood,LepGood_pdgId))" at address 0x2c7bfa0
"energies(lorentz_vectors(vectorOf(nGenPart,GenPart_pt),vectorOf(nGenPart,GenPart_eta),vectorOf(nGenPart,GenPart_phi),vectorOf(nGenPart,GenPart_mass)))" at address 0x448ca00
"energies(lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass)))" at address 0x448bd90
"energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass)))" at address 0x43ed5a0
"evt" at address 0x43f4c70
"lorentz_vectors(vectorOf(nGenPart,GenPart_pt),vectorOf(nGenPart,GenPart_eta),vectorOf(nGenPart,GenPart_phi),vectorOf(nGenPart,GenPart_mass))" at address 0x44187b0
"lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass))" at address 0x4416800
"lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))" at address 0x4415860
"lumi" at address 0x44cbe90
"map(inv_mass:cartProduct(lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass)),lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass))))" at address 0x448b760
"nBJetLoose40" at address 0x44ccab0
"nBJetMedium40" at address 0x44bfbb0
"nBJetTight40" at address 0x43f6440
"nGenPart" at address 0x4414830
"nJet" at address 0x43f2250
"nLepGood" at address 0x44cc470
"nVert" at address 0x43f3450
"os-dilepton" at address 0x2c7cbe0
"pair(count(is_electron:vectorOf(nGenPart,GenPart_pdgId)),count(is_electron:vectorOf(nLepGood,LepGood_pdgId)))" at address 0x2c7c280
"pair(count(is_lepton:vectorOf(nGenPart,GenPart_pdgId)),count(is_lepton:vectorOf(nLepGood,LepGood_pdgId)))" at address 0x2c7c7b0
"pair(count(is_muon:vectorOf(nGenPart,GenPart_pdgId)),count(is_muon:vectorOf(nLepGood,LepGood_pdgId)))" at address 0x2c7c610
"pair(energies(lorentz_vectors(vectorOf(nJet,Jet_pt),vectorOf(nJet,Jet_eta),vectorOf(nJet,Jet_phi),vectorOf(nJet,Jet_mass))),vectorOf(nJet,Jet_eta))" at address 0x2c7a710
"pair(energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))),vectorOf(nLepGood,LepGood_pt))" at address 0x2c7a2a0
"pair(nLepGood,nJet)" at address 0x2c7e3c0
"reduceWith(max:energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))))" at address 0x4489e80
"reduceWith(mean:energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))))" at address 0x43eee70
"reduceWith(min:energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))))" at address 0x44873c0
"reduceWith(range:energies(lorentz_vectors(vectorOf(nLepGood,LepGood_pt),vectorOf(nLepGood,LepGood_eta),vectorOf(nLepGood,LepGood_phi),vectorOf(nLepGood,LepGood_mass))))" at address 0x44327f0
"run" at address 0x43f0590
"ss-dilepton" at address 0x44158d0
"trilepton" at address 0x2c7c660
"vectorOf(nGenPart,GenPart_eta)" at address 0x44321a0
"vectorOf(nGenPart,GenPart_mass)" at address 0x442ef10
"vectorOf(nGenPart,GenPart_motherId)" at address 0x44855a0
"vectorOf(nGenPart,GenPart_motherIndex)" at address 0x44861f0
"vectorOf(nGenPart,GenPart_pdgId)" at address 0x4486dd0
"vectorOf(nGenPart,GenPart_phi)" at address 0x43ee800
"vectorOf(nGenPart,GenPart_pt)" at address 0x4432e40
"vectorOf(nGenPart,GenPart_status)" at address 0x442e370
"vectorOf(nJet,Jet_btagCMVA)" at address 0x4487fa0
"vectorOf(nJet,Jet_eta)" at address 0x448a500
"vectorOf(nJet,Jet_mass)" at address 0x4488c30
"vectorOf(nJet,Jet_phi)" at address 0x4489820
"vectorOf(nJet,Jet_pt)" at address 0x448b140
"vectorOf(nLepGood,LepGood_charge)" at address 0x442a270
"vectorOf(nLepGood,LepGood_eta)" at address 0x442c5d0
"vectorOf(nLepGood,LepGood_mass)" at address 0x442ae40
"vectorOf(nLepGood,LepGood_mcMatchAny)" at address 0x43ee190
"vectorOf(nLepGood,LepGood_mcMatchId)" at address 0x44296f0
"vectorOf(nLepGood,LepGood_mcMatchPdgId)" at address 0x4428b70
"vectorOf(nLepGood,LepGood_mcMatchTau)" at address 0x43ecf10
"vectorOf(nLepGood,LepGood_mcPt)" at address 0x448c3a0
"vectorOf(nLepGood,LepGood_pdgId)" at address 0x442dda0
"vectorOf(nLepGood,LepGood_phi)" at address 0x442ba10
"vectorOf(nLepGood,LepGood_pt)" at address 0x442d1a0
"xsec" at address 0x44ce800
"""


def parse(str_in):
    str_in = "("+str_in+")"

    ends = {}
    nests = {}
    names = {}
    styles = {}
    parens = []
    name = ""
    name_start = 0
    name_end = 0
    for i, char in enumerate(str_in):
        if char == "(":
            nests[name_start] = []
            if parens:
                nests[parens[-1]].append(name_start)
            names[name_start] = name  # save function name
            styles[name_start] = {"shape": "ellipse"}
            name = ""
            parens.append(name_start)
        elif char == ")":
            if name:
                ends[name_start] = name_end
                names[name_start] = name
                styles[name_start] = {"shape": "rectangle"}
                nests[parens[-1]].append(name_start)
                name = ""
            ends[parens.pop()] = i
        elif char in ",:":
            if name:
                ends[name_start] = name_end
                names[name_start] = name
                if char == ",":
                    styles[name_start] = {"shape": "rectangle"}
                else:
                    styles[name_start] = {"shape": "invhouse"}
                nests[parens[-1]].append(name_start)
                name = ""
        else:
            if not name:
                name_start = i
            name += char
            name_end = i

    # clean up duplicate sub-trees
    text = {}
    for start, end in ends.items():
        s = str_in[start:end+1]
        if s in text:
            dup_id = text[s]
            names.pop(start)
            if start in nests:
                nests.pop(start)
            for l in nests.values():
                for i in range(len(l)):
                    if l[i] == start:
                        l[i] = dup_id
        else:
            text[s] = start

    names.pop(0)
    nests.pop(0)

    g = pdp.Dot()

    for id_, name in names.items():
        g.add_node(pdp.Node(str(id_), label=name, **styles[id_]))
    for group_id, children in nests.items():
        for child_id in children:
            g.add_edge(pdp.Edge(str(group_id), str(child_id)))

    with open("outfile.ps", "wb") as f:
        try:
            f.write(g.create_ps())
        except Exception as e:
            print(g.to_string())
            raise e


if __name__ == '__main__':
    vals = log.split('\n')
    vals = [val.split(' at ')[0][1:-1] for val in vals if val]
    for val in vals:
        parse(val)
        input()
