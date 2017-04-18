
IF(LATEX_COMPILER)
    SET(LATEX_DEFAULT_BUILD pdf)
    SET(PDFLATEX_COMPILER xelatex)
    MESSAGE(STATUS "Found LaTeX compiler.")
    INCLUDE(${CMAKE_SOURCE_DIR}/cmake/UseLATEX.cmake)

    ADD_SUBDIRECTORY(presentations/intro/)

ELSE(LATEX_COMPILER)
    MESSAGE(STATUS "No LaTeX found, cannot compile LaTeX documents")
ENDIF(LATEX_COMPILER)
