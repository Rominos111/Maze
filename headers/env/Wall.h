#ifndef MAZE_WALL_H
#define MAZE_WALL_H

#include "MapElem.h"

/**
 * Mur de la map
 */
class Wall : public MapElem {
public:
    /**
     * Constructeur
     */
    Wall();

    /**
     * Destructeur
     */
    ~Wall() override;

    /**
     * Si le mur est plein ou non
     *
     * @return Plein ou non
     */
    [[nodiscard]] bool isFilled() const;

private:
    /**
     * Plein ou non
     */
    bool filled;
};

#endif