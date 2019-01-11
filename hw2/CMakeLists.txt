CMAKE_MINIMUM_REQUIRED  ( VERSION 2.8                                                                                    )
SET                     ( CMAKE_VERBOSE_MAKEFILE true                                                                    )
FILE                    ( GLOB ALLSRCS "*.h" "*.cpp"                                                                     )
ADD_EXECUTABLE          ( encoding encoding.cpp Tries.cpp Tries.h TriesNode.cpp TriesNode.h                              )
ADD_EXECUTABLE          ( decoding decoding.cpp dTries.cpp dTries.h dTriesNode.cpp dTriesNode.h                          )
TARGET_LINK_LIBRARIES   ( encoding                                                                                       )

