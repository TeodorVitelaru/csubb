cmake_minimum_required(VERSION 3.27)
project(sda_lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++/Proiect C++")
include_directories(Teste/Teste)

add_executable(sda_lab1
        "Proiect C++/Proiect C++/App.cpp"
        "Proiect C++/Proiect C++/Matrice.cpp"
        "Proiect C++/Proiect C++/Matrice.h"
        Teste/Teste/TestExtins.cpp
        Teste/Teste/TestExtins.h
        Teste/Teste/TestScurt.cpp
        Teste/Teste/TestScurt.h)
