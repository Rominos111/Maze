#include "../headers/env/Map.h"
#include "../headers/view/MapTerm.h"
#include "../headers/view/MazeWindow.h"
#include "../headers/generation/Kruskal.h"

int main(int argc, char **argv) {
    setenv("DISPLAY", "127.0.0.1:0", true);

    Map map(3, 5);

    Kruskal k(&map);
    k.generate();

    displayMapToTerm(&map);

    MazeWindow window(&map, Position<size_t>(800, 600), "test");

    int code = window.run();

    if (code != EXIT_SUCCESS) {
        std::cout << "erreur fenêtre" << std::endl;
    }

    return code;
}

// EXIT_FAILURE