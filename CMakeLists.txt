cmake_minimum_required(VERSION 3.13)
project(cactus_picker)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_NAME "Cactus_Picker")
add_executable(${EXECUTABLE_NAME} src/main.cpp include/GameStateSystem.h include/Game.h src/Game.cpp include/LeftHand.h include/RightHand.h include/Cactus.h include/Hand.h src/Hand.cpp src/Cactus.cpp src/RightHand.cpp src/LeftHand.cpp include/Spike.h src/Spike.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()