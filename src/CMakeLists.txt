set (SOURCES rfa.cpp 
             stdafx.cpp 
             targetver.h)

add_library (RandomFractalsApp STATIC  ${SOURCES})
target_include_directories(RandomFractalsApp PUBLIC ${PROJECT_SOURCE_DIR}/src )