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
 * Map représentant le labyrinthe<br>
 * <pre>
 *  x x x x x x x x x x x<br>
 *  x O - O - O - O - O x<br>
 *  x | * | * | * | * | x<br>
 *  x O - O - A B O - O x<br>
 *  x | * | * C * | * | x<br>
 *  x O - O - O - O - O x<br>
 *  x | * | * | * | * | x<br>
 *  x O - O - O - O - O x<br>
 *  x | * | * | * | * | x<br>
 *  x O - O - O - O - O x<br>
 *  x x x x x x x x x x x
 * </pre>
 * Les 'O' sont des cases vides<br>
 * Les '─' et '|' sont des murs ou des portes<br>
 * Les '*' sont des intersections, qui ne peuvent pas être supprimées<br>
 * Les 'x' sont des murs extérieurs, qui ne peuvent pas non plus être supprimés<br>
 * <br>
 * 'A' a pour position absolue (5, 3) mais on considère qu'elle est (2, 1)<br>
 * 'B' a pour position absolue (6, 3) mais on considère qu'elle est (2.5, 1)<br>
 * 'C' a pour position absolue (5, 4) mais on considère qu'elle est (2, 1.5)<br>
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
    bool isCellPosValid(const Position<float>& pos) const;

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
     * Set une cellule à partir d'un pointeur vers une cellule
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
     * Set une cellule à partir d'une cellule<br>
     * Utilisé lors de l'égalité, dans Map::Access
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
     * Si une position p pour un mur est valide ou non
     *
     * @param p Position
     *
     * @return Valide ou non
     */
    bool isWallPosValid(const Position<float>& pos) const;

    /**
     * Récupère un pointeur vers un mur
     *
     * @param pos Position
     *
     * @return Pointeur vers le mur
     *
     * @throws range_error Si position hors de la map
     */
    Wall* getWall(const Position<float> &pos);

    /**
     * Set un mur à partir d'un pointeur vers un mur
     *
     * @param pos Position
     * @param other Mur
     *
     * @return Mur modifié
     *
     * @throws range_error Si position hors de la map
     */
    Wall& setWall(const Position<float> &pos, const Wall* other);

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
     * Récupère le vrai nombre de lignes
     *
     * @return Vrai nombre de lignes
     */
    size_t getTrueNbRows() const;

    /**
     * Récupère le vrai nombre de colonnes
     *
     * @return Vrai nombre de colonnes
     */
    size_t getTrueNbCols() const;

    /**
     * Récupère la vraie position interne associée à une position
     *
     * @param pos Position
     *
     * @return Position interne
     */
    static Position<int> getTruePos(const Position<float> &pos);

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
