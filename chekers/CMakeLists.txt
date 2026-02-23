cmake_minimum_required(VERSION 4.0)
project(chekers)

set(CMAKE_CXX_STANDARD 20)




include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable(chekers
        main.cpp
        Board/board.cpp
        Piece/piece.hpp


)


target_link_libraries(chekers
        /opt/homebrew/lib/libsfml-graphics.dylib
        /opt/homebrew/lib/libsfml-window.dylib
        /opt/homebrew/lib/libsfml-system.dylib
)