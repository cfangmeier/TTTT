
ADD_CUSTOM_TARGET(intro
                  rubber --into ${CMAKE_BINARY_DIR}/docs/intro/ intro.tex
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs/intro
                  COMMENT "Build intro presentation with rubber"
                  )
