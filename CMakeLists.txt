set(DEBUG)
# set(RELEASE)
set(ASM_PRE)

cmake_minimum_required(VERSION 3.10)
project(Maze)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

if (RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -O3 -s")
elseif (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
endif()

if (ASM_PRE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
endif()

set(SOURCE_FILES
        src/Main.cpp

        src/util/UnionFind.cpp
        src/util/Observer.cpp
        src/util/Observable.cpp
        src/util/Position.cpp

        src/env/Map.cpp
        src/env/Cell.cpp
        src/env/Map_Access.cpp
        src/env/Map_Iterator.cpp
        src/env/MapElem.cpp
        src/env/Wall.cpp

        src/view/MapTerm.cpp
)

set(HEADER_FILES
        headers/util/UnionFind.h
        headers/util/Observer.h
        headers/util/Observable.h
        headers/util/Observable.fwd.h
        headers/util/Observer.fwd.h
        headers/util/Position.h

        headers/env/Map.h
        headers/env/Cell.h
        headers/env/Map_Access.h
        headers/env/Map_Iterator.h
        headers/env/Map.fwd.h
        headers/env/MapElem.h
        headers/env/Wall.h

        headers/view/MapTerm.h
)

add_executable(Maze ${SOURCE_FILES} ${HEADER_FILES})

set(SFML_ROOT "/mnt/d/GDrive/Programmation/C++/SFML-2.5.1")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Maze ${SFML_LIBRARIES})
endif()