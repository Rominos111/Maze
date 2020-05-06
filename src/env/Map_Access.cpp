#include "../../headers/env/Map_Access.h"

Map::Access::Access(Map& parent, const Position<int> &pos) : parent(parent), pos(pos) {}

Map::Access Map::operator()(const Position<int> &pos)  {
    return Access(*this, pos);
}

Map::Access::operator Cell *() const {
    return parent.getCell(pos);
}

Map::Access& Map::Access::operator=(const Cell *other) {
    parent.setCell(pos, other);
    return *this;
}

Map::Access& Map::Access::operator=(const Cell &other) {
    parent.setCell(pos, other);
    return *this;
}