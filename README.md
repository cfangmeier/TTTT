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
plots/measurements.
