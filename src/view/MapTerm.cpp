#include "../../headers/view/MapTerm.h"

#include "../../headers/env/Cell.h"
#include "../../headers/env/Wall.h"

void displayMapToTerm(Map *map) {
    for (unsigned int row=0; row < map->getNbRows(); row++) {
        for (unsigned int col=0; col < map->getNbCols(); col++) {
            Position<int> pos(row, col);
            Cell *cell = map->getCell(pos);

            std::cout << "O ";

            Position<float> wallPos(pos);
            wallPos += Position<float>(0, 0.5);

            if (map->isWallPosValid(wallPos)) {
                Wall *wall = map->getWall(wallPos);

                if (wall->isFilled()) {
                    std::cout << '-';
                }
                else {
                    std::cout << ' ';
                }

                std::cout << ' ';
            }
        }

        std::cout << std::endl;

        for (unsigned int col=0; col < map->getNbCols(); col++) {
            Position<float> pos(row, col);

            Position<float> vertPos   = pos + Position<float>(0.5, 0);
            Position<float> horizPos = pos + Position<float>(0, 0.5);

            if (map->isWallPosValid(vertPos)) {
                Wall *wall = map->getWall(vertPos);

                if (wall->isFilled()) {
                    std::cout << "|";
                }
                else {
                    std::cout << " ";
                }

                std::cout << " ";

                if (map->isWallPosValid(horizPos)) {
                    std::cout << "  ";
                }
            }
        }

        std::cout << std::endl;
    }
}