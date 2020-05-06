#include "../../headers/env/Map_Iterator.h"
#include "../../headers/env/Map.h"

Map_Iterator::Map_Iterator(Map *map) : map(map), pos(0, 0) {}

int Map_Iterator::getRow() const {
    return pos.getRow();
}

int Map_Iterator::getCol() const {
    return pos.getCol();
}

Position<int> Map_Iterator::getPos() const {
    return pos;
}

Cell *Map_Iterator::getCell() const {
    if (map == nullptr) {
        throw std::invalid_argument("Pointeur null");
    }

    return map->getCell(pos);
}

void Map_Iterator::next() {
    if (map == nullptr) {
        throw std::invalid_argument("Pointeur null");
    }

    int row = pos.getRow();
    int col = pos.getCol() + 1;

    if (col == (int) map->getNbCols()) {
        col = 0;
        row ++;
    }

    if (row == (int) map->getNbRows()) {
        row = 0;
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
