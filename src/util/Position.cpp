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
template<typename U>
Position<T>::Position(const Position<U> p) {
    this->x = (T) p.getX();
    this->y = (T) p.getY();
}

template<typename T>
Position<T>::~Position() = default;

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
T Position<T>::getRows() const {
    return getX();
}

template<typename T>
T Position<T>::getCols() const {
    return getY();
}

template<typename T>
T Position<T>::getNbRows() const {
    return getX();
}

template<typename T>
T Position<T>::getNbCols() const {
    return getY();
}

template<typename T>
void Position<T>::setX(T nx) {
    x = nx;
}

template<typename T>
void Position<T>::setY(T ny) {
    y = ny;
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
void Position<T>::set(T nx, T ny) {
    setX(nx);
    setY(ny);
}

template<typename T>
bool Position<T>::operator==(const Position &pos) const {
    return (x == pos.x && y == pos.y);
}

template<typename T>
bool Position<T>::operator!=(const Position &pos) const {
    return !(*this == pos);
}

template<typename U>
std::ostream &operator<<(std::ostream &output, const Position<U> &pos) {
    output << "(" << pos.x << ", " << pos.y << ")";
    return output;
}

template<typename T>
Position<T> &Position<T>::add(const Position<T> &pos) {
    set(x + pos.getX(), y + pos.getY());
    return *this;
}

template<typename T>
Position<T> &Position<T>::operator+=(const Position<T> &pos) {
    return add(pos);
}

template<typename T>
Position<T> Position<T>::add(const Position<T> &p1, const Position<T> &p2) {
    Position<T> p(p1);
    p.add(p2);
    return p;
}

template<typename T>
Position<T> Position<T>::operator+(const Position &pos) const {
    return add(*this, pos);
}

template<typename T>
Position<T> &Position<T>::sub(const Position<T> &pos) {
    set(x - pos.getX(), y - pos.getY());
    return *this;
}

template<typename T>
Position<T> &Position<T>::operator-=(const Position<T> &pos) {
    return sub(pos);
}

template<typename T>
Position<T> Position<T>::sub(const Position<T> &p1, const Position<T> &p2) {
    Position<T> p(p1);
    p.sub(p2);
    return p;
}

template<typename T>
Position<T> Position<T>::operator-(const Position &pos) const {
    return sub(*this, pos);
}

template<typename T>
template<typename D>
Position<T> &Position<T>::mult(D val) {
    set(x*val, y*val);
    return *this;
}

template<typename T>
template<typename D>
Position<T> &Position<T>::operator*=(D val) {
    return mult(val);
}

template<typename T>
template<typename D>
Position<T> Position<T>::mult(const Position<T> &p, const D val) {
    Position<T> np(p);
    np.mult(val);
    return np;
}

template<typename T>
template<typename D>
Position<T> Position<T>::operator*(D val) const {
    return mult(*this, val);
}

template<typename T>
template<typename D>
Position<T> &Position<T>::div(D val) {
    set(x/val, y/val);
    return *this;
}

template<typename T>
template<typename D>
Position<T> &Position<T>::operator/=(D val) {
    return div(val);
}

template<typename T>
template<typename D>
Position<T> Position<T>::div(const Position<T> &p, const D val) {
    Position<T> np(p);
    np.div(val);
    return np;
}

template<typename T>
template<typename D>
Position<T> Position<T>::operator/(D val) const {
    return div(*this, val);
}

template class Position<int>;
template class Position<unsigned int>;
template class Position<size_t>;
template class Position<float>;

template Position<int>::Position(const Position<int> p);
template Position<int>::Position(const Position<float> p);
template Position<float>::Position(const Position<int> p);
template Position<float>::Position(const Position<float> p);
template Position<size_t>::Position(const Position<int> p);
template Position<int>::Position(const Position<size_t> p);

template Position<int> Position<int>::operator*(int val) const;
template Position<int> Position<int>::operator*(float val) const;
template Position<float> Position<float>::operator*(int val) const;
template Position<float> Position<float>::operator*(float val) const;

template Position<int>& Position<int>::operator*=(int val);
template Position<int>& Position<int>::operator*=(float val);
template Position<float>& Position<float>::operator*=(int val);
template Position<float>& Position<float>::operator*=(float val);

template Position<int> Position<int>::operator/(int val) const;
template Position<float> Position<float>::operator/(int val) const;

template Position<int>& Position<int>::operator/=(int val);
template Position<float>& Position<float>::operator/=(int val);

template std::ostream& operator<<(std::ostream &output, const Position<int> &pos);
template std::ostream& operator<<(std::ostream &output, const Position<unsigned int> &pos);
template std::ostream& operator<<(std::ostream &output, const Position<float> &pos);
template std::ostream& operator<<(std::ostream &output, const Position<size_t> &pos);