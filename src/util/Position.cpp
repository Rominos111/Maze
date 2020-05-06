#include <glob.h>
#include "../../headers/util/Position.h"

template<typename T>
Position<T>::Position() : Position(0, 0) {}

template<typename T>
Position<T>::Position(T p) : Position(p, p) {}

template<typename T>
Position<T>::Position(T x, T y) {
    this->x = x;
    this->y = y;
}

template<typename T>
T Position<T>::getX() const {
    return x;
}

template<typename T>
T Position<T>::getY() const {
    return y;
}

template<typename T>
T Position<T>::getWidth() const {
    return getX();
}

template<typename T>
T Position<T>::getHeight() const {
    return getY();
}

template<typename T>
T Position<T>::getRow() const {
    return getX();
}

template<typename T>
T Position<T>::getCol() const {
    return getY();
}

template<typename T>
void Position<T>::setX(T x) {
    this->x = x;
}

template<typename T>
void Position<T>::setY(T y) {
    this->y = y;
}

template<typename T>
void Position<T>::setWidth(T w) {
    setX(w);
}

template<typename T>
void Position<T>::setHeight(T h) {
    setY(h);
}

template<typename T>
void Position<T>::setRow(T row) {
    setX(row);
}

template<typename T>
void Position<T>::setCol(T col) {
    setY(col);
}

template<typename T>
void Position<T>::set(T x, T y) {
    setX(x);
    setY(y);
}

template<typename T>
bool Position<T>::operator==(const Position &pos) const {
    return (x == pos.x && y == pos.y);
}

template<typename T>
bool Position<T>::operator!=(const Position &pos) const {
    return !(*this == pos);
}

template class Position<int>;
template class Position<size_t>;
