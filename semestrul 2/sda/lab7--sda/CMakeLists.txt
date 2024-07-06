cmake_minimum_required(VERSION 3.27)
project(lab7__sda)

set(CMAKE_CXX_STANDARD 14)

include_directories("TAD Dictionar Ordonat/Proiect C++")
include_directories("TAD Dictionar Ordonat/Teste")

add_executable(lab7__sda
        "TAD Dictionar Ordonat/Proiect C++/App.cpp"
        "TAD Dictionar Ordonat/Proiect C++/DO.cpp"
        "TAD Dictionar Ordonat/Proiect C++/DO.h"
        "TAD Dictionar Ordonat/Proiect C++/Iterator.cpp"
        "TAD Dictionar Ordonat/Proiect C++/Iterator.h"
        "TAD Dictionar Ordonat/Teste/TestExtins.cpp"
        "TAD Dictionar Ordonat/Teste/TestExtins.h"
        "TAD Dictionar Ordonat/Teste/TestScurt.cpp"
        "TAD Dictionar Ordonat/Teste/TestScurt.h")
