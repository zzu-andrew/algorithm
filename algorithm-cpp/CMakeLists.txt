

add_executable(arena arena/arena.cpp arena/main.cpp)
target_include_directories(arena PUBLIC arena)


add_executable(gc gc/gc.cpp gc/main.cpp)
