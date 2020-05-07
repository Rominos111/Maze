#ifndef MAZE_CELL_H
#define MAZE_CELL_H

#include "MapElem.h"

/**
 * Cellule de la map
 */
class Cell : public MapElem {
public:
    /**
     * Constructeur
     */
    Cell();

    /**
     * Destructeur
     */
    ~Cell() override;
};

#endif
