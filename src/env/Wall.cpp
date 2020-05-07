#include "../../headers/env/Wall.h"

#include <iostream>

Wall::Wall() : MapElem(), filled(true) {
    this->TYPE = WALL;
}

Wall::~Wall() = default;

bool Wall::isFilled() const {
    return filled;
}

