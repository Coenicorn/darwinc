cmake_minimum_required(VERSION 3.26)

project(DarwinC VERSION 1.0 DESCRIPTION "An ecosystem simulation written in C" LANGUAGES C)

add_executable(darwinc src/main.c src/world.c src/ecs.c)