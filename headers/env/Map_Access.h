#ifndef MAZE_MAP_ACCESS_H
#define MAZE_MAP_ACCESS_H

#include "Map.h"

/**
 * Gestion des accès pour la surcharge de l'opérateur <code>()</code>
 */
class Map::Access {
public:
    /**
     * Constructeur
     *
     * @param parent Map parente
     * @param pos Position
     */
    Access(Map& parent, const Position<int>& pos);

    /**
     * Surcharge du getter de l'opérateur <code>()</code><br>
     * Exemple : <code>std::cout << m(1, 1) << std::endl;</code>
     *
     * @return Valeur en <code>(row, col)</code>
     */
    operator Cell* () const;

    /**
     * Surcharge du setter de l'opérateur <code>()</code> par référence<br>
     *
     * @param other Autre valeur
     *
     * @return Cellule
     */
    Access& operator = (const Cell* other);

    /**
     * Surcharge du setter de l'opérateur <code>()</code> par valeur<br>
     *
     * @param other Autre valeur
     *
     * @return Cellule
     */
    Access& operator = (const Cell& other);

private:
    /**
     * Map parente
     */
    Map& parent;

    /**
     * Position
     */
    Position<int> pos;
};

#endif