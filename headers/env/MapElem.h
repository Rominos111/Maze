#ifndef MAZE_MAPELEM_H
#define MAZE_MAPELEM_H

/**
 * Types d'éléments de la map
 */
enum MapElemType {
    DEFAULT,
    CELL,
    WALL
};

/**
 * Élément générique de la map
 */
class MapElem {
protected:
    /**
     * Constructeur
     */
    MapElem();

    /**
     * Destructeur virtuel pour utiliser le destructeur des classes filles
     */
    virtual ~MapElem() = default;

    /**
     * Type d'élément
     */
    MapElemType TYPE;
};

#endif
