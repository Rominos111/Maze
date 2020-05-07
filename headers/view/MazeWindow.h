#ifndef MAZE_MAZEWINDOW_H
#define MAZE_MAZEWINDOW_H

#define BACKGROUND_COLOR sf::Color::Red

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../env/Map.h"
#include "../util/Position.h"

/**
 * Affichage d'un labyrinthe à l'écran
 */
class MazeWindow {
public:
    /**
     * Constructeur
     *
     * @param map Map
     * @param size Taille initiale
     * @param title Titre
     */
    MazeWindow(Map *map, const Position<size_t> &size, const std::string& title);

    /**
     * Destructeur
     */
    ~MazeWindow();

    /**
     * Lance la fenêtre
     *
     * @return Code d'erreur
     */
    int run();

private:
    /**
     * Gère les events
     */
    void processEvents();

    /**
     * Met à jour
     */
    void update();

    /**
     * Affiche
     */
    void render();

    /**
     * Gère les entrées clavier
     *
     * @param key Touche
     * @param pressed Enfoncée ou relâchée
     */
    void handleInput(const sf::Keyboard::Key key, bool pressed);

    /**
     * Fenêtre
     */
    sf::RenderWindow window;

    /**
     * Map
     */
    Map* map;

    /**
     * Lancé ou non
     */
     bool running;
};

#endif