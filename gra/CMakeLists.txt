cmake_minimum_required(VERSION 3.10)
project(game)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(game
  src/main.cpp
  src/element.cpp
  src/button.cpp
  src/plansza.cpp
  src/grafika.cpp
  src/Stan.cpp
  src/zasady.cpp 
  src/goniec.cpp 
  src/Kon.cpp 
  src/krol.cpp 
  src/krolowa.cpp 
  src/Pion.cpp 
  src/pionek.cpp 
  src/wieza.cpp 
  src/button.cpp 
  )
target_link_libraries(game PRIVATE SDL2::Main SDL2::TTF SDL2::Image)
target_include_directories(game PRIVATE include )
