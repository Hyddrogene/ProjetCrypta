cmake_minimum_required(VERSION 3.1.0)

project(ProjetCrypta)
add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
add_executable(${PROJECT_NAME} "main.cpp" domaine.cc variable.cc contrainte.cc node.cc)
