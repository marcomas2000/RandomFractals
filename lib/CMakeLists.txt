set (SOURCES BrownianMotion.cpp 
             randomfractals.cpp 
             stdafx.cpp 
             targetver.h)

add_library (RandomFractals STATIC  ${SOURCES})
target_include_directories(RandomFractals PUBLIC ${PROJECT_SOURCE_DIR}/lib )