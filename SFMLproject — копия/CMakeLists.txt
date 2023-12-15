cmake_minimum_required(VERSION 3.23)
project(SFMLproject)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)
link_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/lib)

add_executable(SFMLproject main.cpp)

target_link_libraries(SFMLproject sfml-graphics sfml-window sfml-system)