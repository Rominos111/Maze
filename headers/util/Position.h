#ifndef MAZE_POSITION_H
#define MAZE_POSITION_H

/**
 * Position
 *
 * @tparam T Type des index
 */
template<typename T>
class Position {
public:
    /**
     * Constructeur vide, <code>(0, 0)</code>
     */
    Position();

    /**
     * Constructeur <code>(p, p)</code>
     *
     * @param p Position x et y
     */
    explicit Position(T p);

    /**
     * Constructeur <code>(x, y)</code>
     *
     * @param x Position x
     * @param y Position y
     */
    Position(T x, T y);

    /**
     * Récupère la coordonnée x
     *
     * @return X
     */
    T getX() const;

    /**
     * Récupère la coordonnée y
     *
     * @return Y
     */
    T getY() const;

    /**
     * Alias de getX
     */
    T getWidth() const;

    /**
     * Alias de getY
     */
    T getHeight() const;

    /**
     * Alias de getX
     */
    T getRow() const;

    /**
     * Alias de getY
     */
    T getCol() const;

    /**
     * Setter de x
     *
     * @param x X
     */
    void setX(T x);

    /**
     * Setter de y
     *
     * @param y Y
     */
    void setY(T y);

    /**
     * Alias de setX
     */
    void setWidth(T w);

    /**
     * Alias de setY
     */
    void setHeight(T h);

    /**
     * Alias de setX
     */
    void setRow(T row);

    /**
     * Alias de setY
     */
    void setCol(T col);

    /**
     * Setter
     *
     * @param x X
     * @param y Y
     */
    void set(T x, T y);
private:
    /**
     * Coordonnées
     */
    T x, y;
};

#endif
