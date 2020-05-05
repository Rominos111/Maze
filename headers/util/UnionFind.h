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
    /**
     * Constructeur
     *
     * @param initContent Tableau pour l'initialisation
     * @param size Taille du tableau
     */
    UnionFind(const T initContent[], size_t size);

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

    /**
     * Union de deux éléments
     *
     * @param elem1 Élément 1 à unir
     * @param elem2 Élément 2 à unir
     *
     * @throws invalid_argument Élément non trouvé
     */
    void unite(T elem1, T elem2);

    /**
     * Recherche du représentant d'un élément
     *
     * @param elem Élément
     *
     * @return Représentant
     *
     * @throws invalid_argument Élément non trouvé
     */
    T find(T elem);

    /**
     * Ajoute un élément
     *
     * @param elem Élément
     */
    void add(T elem);

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
