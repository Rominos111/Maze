#include "../../headers/util/UnionFind.h"

template<typename T>
UnionFind<T>::UnionFind() = default;

template<typename T>
UnionFind<T>::UnionFind(const T initContent[], const size_t size) : UnionFind() {
    for (int i=0; i<size; i++) {
        add(initContent[i]);
    }
}

template<typename T>
UnionFind<T>::UnionFind(const std::vector<T> initContent) {
    for (int i=0; i<initContent.size(); i++) {
        add(initContent[i]);
    }
}

template<typename T>
UnionFind<T>::~UnionFind() = default;

template<typename T>
void UnionFind<T>::unite(const T elem1, const T elem2) {
    T repr1 = find(elem1);
    T repr2 = find(elem2);

    reprMap[repr1] = repr2;
}

template<typename T>
T UnionFind<T>::find(const T elem)  {
    T repr;

    try {
        repr = reprMap.at(elem);
    }
    catch (std::out_of_range &e) {
        throw std::invalid_argument("Union-Find : elem not found");
    }

    if (repr != elem) {
        repr = find(repr);
        reprMap.at(elem) = repr;
    }

    return repr;
}

template<typename T>
void UnionFind<T>::add(const T elem) {
    reprMap.emplace(elem, elem);
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const UnionFind<T> &uf) {
    for (auto it = uf.reprMap.begin(); it != uf.reprMap.end(); it++) {
        T key = it->first;
        T value = uf.reprMap.at(key);

        output << key << ':' << value << ' ';
    }

    return output;
}

template std::ostream &operator<<(std::ostream &output, const UnionFind<int> &a);

template class UnionFind<int>;