#include "../../headers/env/Map_Access.h"

Map::Access::Access(Map& parent, Position<int> pos) : parent(parent), pos(pos) {}

Map::Access Map::operator()(Position<int> pos)  {
    return Access(*this, pos);
}

Map::Access::operator Cell *() const {
    return parent.get(pos);
}

Cell &Map::Access::operator=(const Cell *other) {
    return parent.set(pos, other);
}

Cell &Map::Access::operator=(const Cell &other) {
    return parent.set(pos, other);
}
