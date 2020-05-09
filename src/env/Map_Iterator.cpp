#include "../../headers/env/Map_Iterator.h"

#include <cmath>
#include "../../headers/env/Map.h"

Map_Iterator::Map_Iterator(Map *map) :
    Map_Iterator(map, false, false, false) {}

Map_Iterator::Map_Iterator(Map *map, bool iterWall) :
    Map_Iterator(map, iterWall, true, true) {}

Map_Iterator::Map_Iterator(Map *map, bool iterWall, bool iterHoriz) :
    Map_Iterator(map, iterWall, iterHoriz, !iterHoriz) {}

Map_Iterator::Map_Iterator(Map *map, bool iterWall, bool iterHoriz, bool iterVert) {
    this->map = map;
    this->iterWall = iterWall;
    this->iterHoriz = iterHoriz;
    this->iterVert = iterVert;
    this->newLine = false;

    if (iterWall) {
        if (iterHoriz && (iterHoriz != iterVert)) {
            this->pos = Position<float>(0.5, 0);
        }
        else {
            this->pos = Position<float>(0, 0.5);
        }
    }
}

float Map_Iterator::getRow() const {
    return pos.getRow();
}

float Map_Iterator::getCol() const {
    return pos.getCol();
}

Position<float> Map_Iterator::getPos() const {
    return pos;
}

void* Map_Iterator::get() const {
    if (iterWall) {
        return getWall();
    }
    else {
        return getCell();
    }
}

Wall* Map_Iterator::getWall() const {
    if (map == nullptr) {
        throw std::invalid_argument("Pointeur null");
    }

    if (iterWall) {
        return map->getWall(pos);
    }
    else {
        throw std::invalid_argument("getWall sur itérateur cellule");
    }
}

Cell* Map_Iterator::getCell() const {
    if (map == nullptr) {
        throw std::invalid_argument("Pointeur null");
    }

    if (iterWall) {
        throw std::invalid_argument("getCell sur itérateur wall");
    }
    else {
        return map->getCell(pos);
    }
}

bool Map_Iterator::isNewLine() const {
    return newLine;
}

void Map_Iterator::next() {
    if (map == nullptr) {
        throw std::invalid_argument("Pointeur null");
    }

    float row = pos.getRow();
    float col = pos.getCol() + 1;

    if (col > (float) map->getNbCols()-1) {
        newLine = true;

        if (iterWall) {
            if (iterHoriz == iterVert) {
                if (floorf(row) == row) {
                    col = 0;
                }
                else {
                    col = 0.5;
                }

                row += 0.5;
            }
            else if (iterVert) {
                col = 0.5;
                row ++;
            }
            else {
                col = 0;
                row ++;
            }
        }
        else {
            col = 0;
            row ++;
        }
    }
    else {
        newLine = false;
    }

    if (row > (float) map->getNbRows()-1) {
        map = nullptr;
    }

    pos.set(row, col);
}

Map_Iterator &Map_Iterator::operator++() {
    next();
    return *this;
}

// NOLINTNEXTLINE
const Map_Iterator Map_Iterator::operator++(int) {
    const Map_Iterator iter = *this;
    next();
    return iter;
}

bool Map_Iterator::operator==(const Map_Iterator &iter) const {
    if (map == nullptr || iter.map == nullptr) {
        return (map == iter.map);
    }
    else {
        return (pos == iter.pos);
    }
}

bool Map_Iterator::operator!=(const Map_Iterator &iter) const {
    return !(*this == iter);
}
