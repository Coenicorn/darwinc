project(darwinc)

set(sources
    main.c
    world.c
)

add_executable(darwinc ${sources})

target_link_libraries(darwinc PUBLIC cecs)
target_include_directories(darwinc PUBLIC ${PROJECT_SOURCE_DIR}/cecs/src)