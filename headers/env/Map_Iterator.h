#ifndef MAZE_MAP_ITERATOR_H
#define MAZE_MAP_ITERATOR_H

#include <cmath>

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
     * Constructeur
     *
     * @param map Map à itérer
     * @param iterWall Itération selon les murs ou les cellules
     */
    Map_Iterator(Map *map, bool iterWall);

    /**
     * Constructeur
     *
     * @param map Map à itérer
     * @param iterWall Itération selon les murs ou les cellules
     * @param iterHoriz Itération selon les murs horizontaux
     */
    Map_Iterator(Map *map, bool iterWall, bool iterHoriz);

    /**
     * Getter de ligne
     *
     * @return Ligne
     */
    [[nodiscard]] float getRow() const;

    /**
     * Getter de colonne
     *
     * @return Colonne
     */
    [[nodiscard]] float getCol() const;

    /**
     * Getter de position
     *
     * @return Position
     */
    [[nodiscard]] Position<float> getPos() const;

    /**
     * Getter, faire un cast lors de l'utilisation
     *
     * @return Pointeur vers un élément
     *
     * @throws invalid_argument Si la map est null, donc si itérateur de fin
     */
    [[nodiscard]] void* get() const;

    /**
     * Getter d'un mur
     *
     * @return Pointeur du mur
     *
     * @throws invalid_argument Si l'itérateur n'est pas sur un mur, ou itérateur de fin
     */
    [[nodiscard]] Wall* getWall() const;

    /**
     * Getter d'une cellule
     *
     * @return Pointeur de la cellule
     *
     * @throws invalid_argument Si l'itérateur n'est pas sur une cellule, ou itérateur de fin
     */
    [[nodiscard]] Cell* getCell() const;

    /**
     * Nouvelle ligne ou non
     *
     * @return Nouvelle ligne
     */
    [[nodiscard]] bool isNewLine() const;

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
    [[nodiscard]] bool operator==(const Map_Iterator& iter) const;

    /**
     * Opérateur de différence
     *
     * @param iter Autre itérateur
     *
     * @return Si itérateurs différents
     */
    [[nodiscard]] bool operator!=(const Map_Iterator& iter) const;

private:
    /**
     * Constructeur général
     *
     * @param map Map
     * @param iterWall Itération selon les murs ou non
     * @param iterHoriz Itération selon les murs horizontaux
     * @param iterVert Itération selon les murs verticaux
     */
    Map_Iterator(Map *map, bool iterWall, bool iterHoriz, bool iterVert);

    /**
     * Map de référence de l'itérateur
     */
    const Map *map;

    /**
     * Position actuelle de l'itérateur
     */
    Position<float> pos;

    /**
     * Itération selon les murs ou les cellules
     */
    bool iterWall;

    /**
     * Itération selon les murs horizontaux
     */
    bool iterHoriz;

    /**
     * Itération selon les murs verticaux
     */
    bool iterVert;

    /**
     * Nouvelle ligne ou non
     */
    bool newLine;
};

#endif