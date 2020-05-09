#include "../../headers/generation/Kruskal.h"

Kruskal::Kruskal(Map *mapArg) {
    this->map = mapArg;
}

Kruskal::~Kruskal() = default;

void Kruskal::generate() {
    for (auto iter=map->iterCell(); iter!=map->iterEnd(); iter++) {
        Position<float> wallVert(iter.getPos());
        wallVert += Position<float>(0.5, 0);

        Position<float> wallHoriz(iter.getPos());
        wallHoriz += Position<float>(0, 0.5);

        if (map->isWallPosValid(wallVert)) {
            bool val = Random::get<bool>(0.25);

            if (val) {
                map->getWall(wallVert)->breakWall();
            }
        }

        if (map->isWallPosValid(wallHoriz)) {
            bool val = Random::get<bool>(0.25);

            if (val) {
                map->getWall(wallHoriz)->breakWall();
            }
        }
    }
}