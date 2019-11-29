cmake_minimum_required(VERSION 3.15)
project(Proyecto_Rivas)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto_Rivas main.cpp
        Almacen.cpp
        Almacen.h
        funciones.cpp
        Robot.cpp
        Instrucciones.cpp
        Objeto.cpp)