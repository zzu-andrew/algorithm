

add_executable(arena arena/arena.cpp arena/main.cpp)
target_include_directories(arena PUBLIC arena)


add_executable(gc gc/gc.cpp gc/main.cpp)

add_executable(lru lru/main.cpp lru/lru_cache.cpp)
target_include_directories(lru
        PUBLIC lru)


