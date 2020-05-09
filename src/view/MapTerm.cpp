#include "../../headers/view/MapTerm.h"

#include "../../headers/env/Cell.h"
#include "../../headers/env/Wall.h"

void displayBorderRow(Map *map, bool up) {
    if (up) {
        std::cout << "╔";
    }
    else {
        std::cout << "╚";
    }

    for (unsigned int i=0; i<map->getNbCols()-1; i++) {
        std::cout << "────";
    }

    std::cout << "───";

    if (up) {
        std::cout << "╗";
    }
    else {
        std::cout << "╝";
    }

    std::cout << std::endl;
}

void displayMapToTerm(Map *map) {
    auto iterCell = map->iterCell();
    auto iterWallHoriz = map->iterWallHoriz();
    auto iterWallVert = map->iterWallVert();

    displayBorderRow(map, true);

    while (iterCell != map->iterEnd()) {
        if (iterCell.getCol() == 0) {
            std::cout << "│";
        }

        std::cout << " # ";

        if ((unsigned int) iterCell.getCol() != map->getNbCols()-1) {
            Wall *wall = (Wall*) iterWallVert.get();
            iterWallVert ++;

            if (wall->isFilled()) {
                std::cout << "│";
            }
            else {
                std::cout << ' ';
            }
        }

        iterCell ++;

        if (iterCell.isNewLine()) {
            std::cout << "│" << std::endl;

            if (iterCell != map->iterEnd()) {
                std::cout << "│";

                do {
                    Wall *wall = (Wall*) iterWallHoriz.get();

                    if (wall->isFilled()) {
                        std::cout << "───";
                    }
                    else {
                        std::cout << "   ";
                    }

                    iterWallHoriz++;

                    if (iterWallHoriz.isNewLine()) {
                        std::cout << "│";
                    }
                    else {
                        std::cout << "╬";
                    }
                }
                while (!iterWallHoriz.isNewLine());

                std::cout << std::endl;
            }
        }
    }

    displayBorderRow(map, false);
}