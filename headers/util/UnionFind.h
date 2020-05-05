#ifndef MAZE_UNIONFIND_H
#define MAZE_UNIONFIND_H

#include <vector>
#include <map>
#include <iostream>

/**
 * Union-Find
 *
 * @tparam T Type du contenu
 */
template<typename T>
class UnionFind {
public:
    // NOLINTNEXTLINE : const
    /**
     * Constructeur
     *
     * @param initContent Tableau pour l'initialisation
     * @param size Taille du tableau
     */
    UnionFind(const T initContent[], const size_t size);

    /**
     * Constructeur
     *
     * @param initContent Contenu à l'initialisation
     */
    UnionFind(const std::vector<T> initContent);

    /**
     * Constructeur
     */
    UnionFind();

    /**
     * Destructeur
     */
    ~UnionFind();

    // NOLINTNEXTLINE : const
    /**
     * Union de deux éléments
     *
     * @param elem1 Élément 1 à unir
     * @param elem2 Élément 2 à unir
     *
     * @throws invalid_argument Élément non trouvé
     */
    void unite(const T elem1, const T elem2);

    // NOLINTNEXTLINE : const
    /**
     * Recherche du représentant d'un élément
     *
     * @param elem Élément
     *
     * @return Représentant
     *
     * @throws invalid_argument Élément non trouvé
     */
    T find(const T elem);

    // NOLINTNEXTLINE : const
    /**
     * Ajoute un élément
     *
     * @param elem Élément
     */
    void add(const T elem);

    /**
     * Override '<<' pour stdout
     *
     * @tparam J Type du contenu d'Union-Find
     *
     * @param output Stream de sortie
     * @param uf Instance de Union-Find
     *
     * @return Stream de sortie
     */
    template <typename J>
    friend std::ostream &operator<<(std::ostream &output, const UnionFind<J> &uf);

private:
    /**
     * Map, implémentation interne<br>
     * Clé : élément<br>
     * Valeur : représentant
     */
    std::map<T, T> reprMap;
};

#endif
