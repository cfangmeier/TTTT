TTTT Production Cross-Section Measurement
=========================================

This project contains the code, documentation, and results of the TTTT
production cross-section measurment in the tri-lepton channel.

To run this analysis, first aquire relevant MC files for signal(TTTT), and main
backgrounds(TTW, TTZ, TT). These should be in the "Minitree" format. Then
checkout the [code](https://github.com/cfangmeier/TTTT) from Github. After
acquiring the code, follow the standard cmake build process of

```bash
cd project_directory
mkdir build
cd build
cmake ..
make
```

Once the code has been built, there should be a `main` executable in the build directory. Call it with the syntax

```bash
./main -f path_to_minitree_file
```


This will create a results `ROOT` file containing a set of histograms extracted
from the Minitree. Create one of these for each input Minitree. The results are
then usually processed in Jupyter Notebooks to produce final
plots/measurements. For example, a basic listing of generated histograms can be
found [here](./TTTT_Analysis.html)

A brief rundown of the general analysis framework, FilVal, can be found [here](./md__home_caleb_Sources_TTTT_AboutFilVal.html).

References
==========
  - **Four Tops for LHC** ([arXiv](https://arxiv.org/abs/1611.05032v1)) <br/>
    A theory paper outlining a general strategy for measuring tttt cross-section using the SS-dilepton and trilepton channels
  - **Efficient Identification of Boosted Semileptonic Top Quarks at the LHC** ([arXiv](https://arxiv.org/abs/1007.2221)) <br/>
    Detailed description of the "mini-iso" requirement.
  - **Top-tagging: A Method for Identifying Boosted Hadronic Tops** ([arXiv](https://arxiv.org/abs/0806.0848)) <br/>
    Description of how to identify hadronically decaying Tops. ie. t->b + W(->q + \bar{q})
