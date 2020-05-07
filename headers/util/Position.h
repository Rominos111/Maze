#ifndef MAZE_POSITION_H
#define MAZE_POSITION_H

#include <ostream>

/**
 * Position
 *
 * @tparam T Type des variables
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
     * Constructeur permettant le cast
     *
     * @tparam U Type de la position à cast
     *
     * @param p Position à cast
     */
    template<typename U>
    Position(const Position<U> p);

    /**
     * Constructeur <code>(x, y)</code>
     *
     * @param x Position x
     * @param y Position y
     */
    Position(T x, T y);

    /**
     * Destructeur
     */
    ~Position();

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
     * Alias de getX
     */
    T getRows() const;

    /**
     * Alias de getY
     */
    T getCols() const;

    /**
     * Alias de getX
     */
    T getNbRows() const;

    /**
     * Alias de getY
     */
    T getNbCols() const;

    /**
     * Setter de x
     *
     * @param nx X
     */
    void setX(T nx);

    /**
     * Setter de y
     *
     * @param ny Y
     */
    void setY(T ny);

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
     * @param nx X
     * @param ny Y
     */
    void set(T nx, T ny);

    /**
     * Opérateur de flux
     *
     * @param output Flux de sortie
     * @param pos Position
     *
     * @return Flux de sortie écrit
     */
    template <typename U>
    friend std::ostream &operator<<(std::ostream &output, const Position<U> &pos);

    /**
     * Opérateur d'égalité
     *
     * @param pos Autre position
     *
     * @return Positions égales
     */
    bool operator==(const Position& pos) const;

    /**
     * Opérateur de différence
     *
     * @param pos Autre position
     *
     * @return Positions différentes
     */
    bool operator!=(const Position& pos) const;

    /**
     * Ajoute une position
     *
     * @param pos Position à ajouter
     *
     * @return Position changée
     */
    Position<T>& add(const Position<T> &pos);

    /**
     * Ajoute une position
     *
     * @param pos Position à ajouter
     *
     * @return Position changée
     */
    Position<T>& operator+=(const Position<T> &pos);

    /**
     * Ajoute deux positions
     *
     * @param p1 Position à ajouter
     * @param p2 Position à ajouter
     *
     * @return Position
     */
    static Position<T> add(const Position<T> &p1, const Position<T> &p2);

    /**
     * Ajoute deux positions <br>
     * Le cast se fait sur T, le type de l'instance présente
     *
     * @param pos Position à ajouter
     *
     * @return Position
     */
    Position<T> operator+(const Position &pos) const;

    /**
     * Soustrait une position
     *
     * @param pos Position à soustraire
     *
     * @return Position changée
     */
    Position<T>& sub(const Position<T> &pos);

    /**
     * Soustrait une position
     *
     * @param pos Position à soustraire
     *
     * @return Position changée
     */
    Position<T>& operator-=(const Position<T> &pos);

    /**
     * Soustrait deux positions
     *
     * @param p1 Position
     * @param p2 Position à soustraire
     *
     * @return Position
     */
    static Position<T> sub(const Position<T> &p1, const Position<T> &p2);

    /**
     * Soustrait deux positions <br>
     * Le cast se fait sur T, le type de l'instance présente
     *
     * @param pos Position à soustraire
     *
     * @return Position
     */
    Position<T> operator-(const Position& pos) const;

    /**
     * Multiplie la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T>& mult(D val);

    /**
     * Multiplie la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T>& operator*=(D val);

    /**
     * Multiplie une position
     *
     * @param p Position à multiplier
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    static Position<T> mult(const Position<T> &p, const D val);

    /**
     * Multiplie la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T> operator*(D val) const;

    /**
     * Divise la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T>& div(D val);

    /**
     * Divise la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T>& operator/=(D val);

    /**
     * Divise une position
     *
     * @param p Position à diviser
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    static Position<T> div(const Position<T> &p, const D val);

    /**
     * Divise la position
     *
     * @param val Coefficient
     *
     * @return Position
     */
    template<typename D>
    Position<T> operator/(D val) const;

private:
    /**
     * Coordonnées
     */
    T x, y;
};

#endif

