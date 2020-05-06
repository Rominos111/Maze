#include "../../headers/env/Map.h"

Map::Map(size_t nbRows, size_t nbCols) {
    size = Position<size_t>(nbRows, nbCols);
    trueSize = Position<size_t>(Position<int>(size) * 2 + Position<int>(1, 1));
    reset();
}

Map::~Map() {
    for (auto iter=begin(); iter!=end(); iter++) {
        delete iter.getCell();
    }
}

void Map::reset() {
    for (unsigned int row=0; row<getNbRows(); row++) {
        std::vector<MapElem*> vect;

        for (unsigned int col=0; col<getNbCols(); col++) {
            if (row % 2 == 0 || col % 2 == 0) {
                vect.push_back(new Wall());
            }
            else {
                vect.push_back(new Cell());
            }
        }

        content.push_back(vect);
    }
}

bool Map::isCellPosValid(const Position<int>& pos) const {
    bool okRow = (pos.getRow() >= 0 && pos.getRow() < (int) getNbRows());
    bool okCol = (pos.getCol() >= 0 && pos.getCol() < (int) getNbCols());

    return okRow && okCol;
}

Cell* Map::getCell(const Position<int> &pos) const {
    if (isCellPosValid(pos)) {
        return (Cell*) content.at(pos.getRow()).at(pos.getCol());
    }
    else {
        throw std::range_error("Get hors de la map");
    }
}

Cell& Map::setCell(const Position<int> &pos, const Cell *other) {
    return (Cell &) (content[pos.getRow()][pos.getCol()] = (Cell *) other);
}

Cell& Map::setCell(const Position<int> &pos, Cell other) {
    return (Cell &) (content[pos.getRow()][pos.getCol()] = &other);
}

size_t Map::getNbRows() const {
    return size.getRow();
}

size_t Map::getNbCols() const {
    return size.getCol();
}

Map_Iterator Map::begin() {
    return Map_Iterator(this);
}

Map_Iterator Map::end() {
    return Map_Iterator(nullptr);
}
