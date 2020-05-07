#ifndef MAZE_KRUSKAL_H
#define MAZE_KRUSKAL_H

#include "../env/Map.h"

#include "../../lib/effolkronium/random.hpp"

using Random = effolkronium::random_static;

class Kruskal {
public:
    explicit Kruskal(Map *map);
    ~Kruskal();

    void generate();

private:
    Map *map;
};

#endif