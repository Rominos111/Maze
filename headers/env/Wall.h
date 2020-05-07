#ifndef MAZE_WALL_H
#define MAZE_WALL_H

#include "MapElem.h"

class Wall : public MapElem {
public:
    Wall();
    ~Wall();
    [[nodiscard]] bool isFilled() const;

private:
    bool filled;
};

#endif