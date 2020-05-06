#ifndef MAZE_MAP_H
#define MAZE_MAP_H

#include <vector>

#include "Map.fwd.h"
#include "Map_Iterator.h"
#include "MapElem.h"
#include "Cell.h"
#include "Wall.h"

#include "../util/Observable.h"
#include "../util/Position.h"

/**
 * Map
 */
class Map : public Observable {
public:
    /**
     * Constructeur
     *
     * @param nbCols Nombre de lignes
     * @param nbRows Nombre de colonnes
     */
    Map(size_t nbRows, size_t nbCols);

    /**
     * Destructeur
     */
    ~Map();

    /**
     * Réinitialise la map
     */
    void reset();

    /**
     * Récupère le nombre de lignes
     *
     * @return Nombre de lignes
     */
    size_t getNbRows() const;

    /**
     * Récupère le nombre de colonnes
     *
     * @return Nombre de colonnes
     */
    size_t getNbCols() const;

    /**
     * Si une position p pour une cellule est valide ou non
     *
     * @param p Position
     *
     * @return Valide ou non
     */
    bool isCellPosValid(const Position<int>& p) const;

    /**
     * Récupère un pointeur vers une cellule
     *
     * @param pos Position
     *
     * @return Pointeur vers la cellule
     *
     * @throws range_error Si position hors de la map
     */
    Cell* getCell(const Position<int> &pos) const;

    /**
     * Set une case à partir d'un pointeur vers une cellule
     *
     * @param pos Position
     * @param other Cellule
     *
     * @return Cellule modifiée
     *
     * @throws range_error Si position hors de la map
     */
    Cell& setCell(const Position<int> &pos, const Cell* other);

    /**
     * Set une case à partir d'une cellule
     *
     * @param pos Position
     * @param other Cellule
     *
     * @return Cellule modifiée
     *
     * @throws range_error Si position hors de la map
     */
    Cell& setCell(const Position<int> &pos, Cell other);

    /**
     * Gestion des accès pour la surcharge de l'opérateur <code>()</code>
     */
    class Access;

    /**
     * Surcharge de l'opérateur <code>()</code> <br>
     * Exemple : <code>m(1, 1) = c;</code>
     *
     * @param row Ligne
     * @param col Colonne
     *
     * @return Access
     */
    Access operator () (const Position<int>& pos);

    /**
     * Début de l'itérateur
     *
     * @return Itérateur
     */
    Map_Iterator begin();

    /**
     * Fin de l'itérateur
     *
     * @return Itérateur
     */
    Map_Iterator end();
private:
    /**
     * Dimension
     */
    Position<size_t> size;

    /**
     * Vraies dimensions
     */
    Position<size_t> trueSize;

    /**
     * Contenu
     */
    std::vector<std::vector<MapElem*>> content;
};

#endif
