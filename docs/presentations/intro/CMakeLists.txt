
ADD_LATEX_DOCUMENT(intro.tex
                   IMAGE_DIRS . figures
                   # Add the feynman diagrams manually because UseLATEX wants to 
                   # generate the pngs if the eps files are included
                   IMAGES figures/feynman-diagrams/T-b_W-ln.png
                          figures/feynman-diagrams/T-b_W.png
                          figures/feynman-diagrams/T-b_W-qq.png )
