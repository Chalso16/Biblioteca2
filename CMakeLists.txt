cmake_minimum_required(VERSION 4.2)
project(Biblioteca2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca2 main.cpp
        Material.cpp
        Material.h
        Libro.cpp
        Libro.h
        Revista.cpp
        Revista.h
        Estanteria.cpp
        Estanteria.h)
