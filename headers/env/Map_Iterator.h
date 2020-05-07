#ifndef MAZE_MAP_ITERATOR_H
#define MAZE_MAP_ITERATOR_H

#include "Map.fwd.h"
#include "MapElem.h"
#include "Cell.h"
#include "Wall.h"
#include "../util/Position.h"

/**
 * Itérateur de Map
 */
class Map_Iterator {
public:
    /**
     * Constructeur
     *
     * @param map Map à itérer
     */
    explicit Map_Iterator(Map *map);

    /**
     * Getter de ligne
     *
     * @return Ligne
     */
    int getRow() const;

    /**
     * Getter de colonne
     *
     * @return Colonne
     */
    int getCol() const;

    /**
     * Getter de position
     *
     * @return Position
     */
    Position<int> getPos() const;

    /**
     * Getter de cellule
     *
     * @return Pointeur vers la cellule
     *
     * @throws invalid_argument Si la map est null, donc si itérateur de fin
     */
    Cell* getCell() const;

    /**
     * Nouvelle ligne ou non
     *
     * @return Nouvelle ligne
     */
    bool isNewLine() const;

    /**
     * Passe au suivant
     *
     * @throws invalid_argument Si la map est null, donc si itérateur de fin
     */
    void next();

    /**
     * Opérateur pré (<code>++var</code>)<br>
     *
     * @return Itérateur incrémenté
     */
    Map_Iterator& operator++();

    /**
     * Opérateur post (<code>var++</code>)<br>
     *
     * @return Itérateur non incrémenté, mais l'itérateur courant est bien incrémenté
     */
    const Map_Iterator operator++(int);

    /**
     * Opérateur d'égalité
     *
     * @param iter Autre itérateur
     *
     * @return Si itérateurs égaux
     */
    bool operator==(const Map_Iterator& iter) const;

    /**
     * Opérateur de différence
     *
     * @param iter Autre itérateur
     *
     * @return Si itérateurs différents
     */
    bool operator!=(const Map_Iterator& iter) const;

private:
    /**
     * Map de référence de l'itérateur
     */
    const Map *map;

    /**
     * Position actuelle de l'itérateur
     */
    Position<int> pos;
};

#endif