#include "../headers/env/Map.h"

int main() {
    Map m(10, 10);

    Cell *c = m(Position(0, 0));

    m(Position(0, 0)) = c;
}
