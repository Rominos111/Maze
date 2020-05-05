#include "../../headers/env/Map.h"

Map::Map(size_t nbRows, size_t nbCols) {
    size = Position<size_t>(nbRows, nbCols);
    reset();
}

Map::~Map() = default;

void Map::reset() {
    for (int row=0; row<getNbRows(); row++) {
        std::vector<Cell*> vect;

        for (int col=0; col<getNbCols(); col++) {
            Cell *cell = new Cell();

            vect.push_back(cell);
        }

        content.push_back(vect);
    }
}

bool Map::isCellPosValid(Position<int> pos) const {
    return (pos.getRow() >= 0 && pos.getRow() < getNbRows() && pos.getCol() >= 0 && pos.getCol() < getNbCols());
}

Cell* Map::get(Position<int> pos) const {
    if (isCellPosValid(pos)) {
        return content.at(pos.getRow()).at(pos.getCol());
    }
    else {
        throw std::range_error("Get hors de la map");
    }
}

Cell &Map::set(Position<int> pos, const Cell *other) {
    return (Cell &) (content[pos.getRow()][pos.getCol()] = (Cell *) other);
}

Cell &Map::set(Position<int> pos, Cell other) {
    return (Cell &) (content[pos.getRow()][pos.getCol()] = &other);
}

size_t Map::getNbRows() const {
    return size.getRow();
}

size_t Map::getNbCols() const {
    return size.getCol();
}
