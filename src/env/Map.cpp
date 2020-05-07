#include "../../headers/env/Map.h"

#include <cmath>

Map::Map(size_t nbRows, size_t nbCols) {
    size = Position<size_t>(nbRows, nbCols);
    trueSize = Position<size_t>(Position<int>(size) * 2 + Position<int>(1, 1));
    reset();
}

Map::~Map() {
    for (unsigned int row=0; row<getTrueNbRows(); row++) {
        for (unsigned int col=0; col<getTrueNbCols(); col++) {
            if (row % 2 == 0 || col % 2 == 0) {
                delete (Wall*) content.at(row).at(col);
            }
            else {
                delete (Cell*) content.at(row).at(col);
            }
        }
    }
}

void Map::reset() {
    for (unsigned int row=0; row<getTrueNbRows(); row++) {
        std::vector<void*> vect;

        for (unsigned int col=0; col<getTrueNbCols(); col++) {
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

bool Map::isCellPosValid(const Position<float>& pos) const {
    float row = pos.getRow(), col = pos.getCol();

    bool okIntRow = (floorf(row) == row);
    bool okIntCol = (floorf(col) == col);
    bool okRow = (row >= 0 && row < (float) getNbRows());
    bool okCol = (col >= 0 && col < (float) getNbCols());

    return okRow && okCol && okIntRow && okIntCol;
}

Cell* Map::getCell(const Position<int> &pos) const {
    if (isCellPosValid(pos)) {
        return (Cell*) &(content.at(pos.getRow()).at(pos.getCol()));
    }
    else {
        throw std::range_error("getCell hors de la map");
    }
}

Cell& Map::setCell(const Position<int> &pos, const Cell *other) {
    if (isCellPosValid(pos)) {
        return (Cell&) (content[pos.getRow()][pos.getCol()] = (void*) other);
    }
    else {
        throw std::range_error("setCell hors de la map");
    }
}

Cell& Map::setCell(const Position<int> &pos, Cell other) {
    if (isCellPosValid(pos)) {
        return (Cell&) (content[pos.getRow()][pos.getCol()] = (void*) &other);
    }
    else {
        throw std::range_error("setCell hors de la map");
    }
}

bool Map::isWallPosValid(const Position<float>& pos) const {
    bool valid = true;

    float rowFloatingPoint = pos.getRow() - floorf(pos.getRow());
    float colFloatingPoint = pos.getCol() - floorf(pos.getCol());

    if ((rowFloatingPoint == 0.5f) != (colFloatingPoint == 0.5f)) {
        // XOR bizarre mais efficace

        Position<int> newPos = getTruePos(pos);

        if (newPos.getRow() <= 0 || newPos.getRow() >= (int) getTrueNbRows() - 1) {
            valid = false;
        }

        if (newPos.getCol() <= 0 || newPos.getCol() >= (int) getTrueNbCols() - 1) {
            valid = false;
        }
    }
    else {
        valid = false;
    }

    return valid;
}

Wall* Map::getWall(const Position<float> &pos) {
    if (isWallPosValid(pos)) {
        return (Wall*) &(content.at(pos.getRow()).at(pos.getCol()));
    }
    else {
        throw std::range_error("getWall hors de la map");
    }
}

Wall& Map::setWall(const Position<float> &pos, const Wall *other) {
    if (isWallPosValid(pos)) {
        return (Wall&) (content[pos.getRow()][pos.getCol()] = (void*) other);
    }
    else {
        throw std::range_error("setWall hors de la map");
    }
}

size_t Map::getNbRows() const {
    return size.getRow();
}

size_t Map::getNbCols() const {
    return size.getCol();
}

size_t Map::getTrueNbRows() const {
    return trueSize.getRow();
}

size_t Map::getTrueNbCols() const {
    return trueSize.getCol();
}

Map_Iterator Map::begin() {
    return Map_Iterator(this);
}

Map_Iterator Map::end() {
    return Map_Iterator(nullptr);
}

Position<int> Map::getTruePos(const Position<float> &pos) {
    Position<float> newPos(pos);
    newPos *= 2;
    newPos += Position(1, 1);
    return newPos;
}
