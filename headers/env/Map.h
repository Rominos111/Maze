#ifndef MAZE_MAP_H
#define MAZE_MAP_H

#include <vector>

#include "Cell.h"
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
    Map(size_t nbCols, size_t nbRows);

    /**
     * Destructeur
     */
    ~Map();

    /**
     * Réinitialise la map
     */
    void reset();

    /**
     * Si une position p pour une cellule est valide ou non
     *
     * @param p Position
     *
     * @return Valide ou non
     */
    bool isCellPosValid(Position<int> p) const;

    /**
     * Récupère un pointeur vers une cellule
     *
     * @param pos Position
     *
     * @return Pointeur vers la cellule
     *
     * @throws range_error Si position hors de la map
     */
    Cell* get(Position<int> pos) const;

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
     * Set une case à partir d'un pointeur vers une cellule
     *
     * @param pos Position
     * @param other Cellule
     *
     * @return Cellule modifiée
     *
     * @throws range_error Si position hors de la map
     */
    Cell& set(Position<int> pos, const Cell* other);

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
    Cell& set(Position<int> pos, Cell other);

    /**
     * Gestion des accès pour la surcharge de l'opérateur <code>()</code>
     */
    class Access {
    public:
        /**
         * Constructeur
         *
         * @param parent Map parente
         * @param pos Position
         */
        Access(Map& parent, Position<int> pos);

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
        Cell& operator = (const Cell* other);

        /**
         * Surcharge du setter de l'opérateur <code>()</code> par valeur<br>
         *
         * @param other Autre valeur
         *
         * @return Cellule
         */
        Cell& operator = (const Cell& other);

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

    /**
     * Surcharge de l'opérateur <code>()</code> <br>
     * Exemple : <code>m(1, 1) = c;</code>
     *
     * @param row Ligne
     * @param col Colonne
     *
     * @return Access
     */
    Access operator () (Position<int> pos);
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
    std::vector<std::vector<Cell*>> content;
};

#endif
