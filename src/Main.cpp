#include <iostream>
#include "../headers/util/UnionFind.h"

int main() {
    int init[] = {7, 8, 9};

    UnionFind<int> uf(init, 3);

    uf.add(5);

    std::cout << uf;

    return 0;
}
