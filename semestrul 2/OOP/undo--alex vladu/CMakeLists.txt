cmake_minimum_required(VERSION 3.27)
project(poriect_alex_vladu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(poriect_alex_vladu
        array.c
        array.h
        controller.c
        controller.h
        domain.c
        domain.h
        main.c
        repository.c
        repository.h
        ui.c
        ui.h
        validator.c
        validator.h)
