# FIND_PACKAGE(LATEX)
SET(LATEX_DEFAULT_BUILD pdf)
SET(PDFLATEX_COMPILER xelatex)
INCLUDE(${CMAKE_SOURCE_DIR}/cmake/UseLATEX.cmake)

IF(LATEX_COMPILER)

##############################################################################
    SET(LATEX_OUTPUT_PATH ${CMAKE_BINARY_DIR}/intro)
    ADD_LATEX_DOCUMENT(intro.tex
                       INPUTS beamerthemebjeldbak.sty
                       IMAGE_DIRS  . figures
                       # Add the feynman diagrams manually because UseLATEX wants to 
                       # generate the pngs if the eps files are included
                       IMAGES figures/feynman-diagrams/T-b_W-ln.png
                              figures/feynman-diagrams/T-b_W.png
                              figures/feynman-diagrams/T-b_W-qq.png )
##############################################################################

ELSE(LATEX_COMPILER)
    MESSAGE(STATUS "No LaTeX found, cannot compile LaTeX documents")
ENDIF(LATEX_COMPILER)
