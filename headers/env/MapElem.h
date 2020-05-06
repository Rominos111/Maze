#ifndef MAZE_MAPELEM_H
#define MAZE_MAPELEM_H

enum MapElemType {
    CELL,
    WALL
};

class MapElem {
protected:
    MapElemType TYPE;
};

#endif
