#include "../../headers/view/MazeWindow.h"

MazeWindow::MazeWindow(Map *map, const Position<size_t> &size, const std::string& title) {
    window.create(sf::VideoMode(size.getWidth(), size.getHeight()), title);
    running = false;
    this->map = map;
}

MazeWindow::~MazeWindow() = default;

int MazeWindow::run() {
    if (running) {
        throw std::runtime_error("Fenêtre déjà ouverte");
    }

    running = true;

    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }

    return EXIT_SUCCESS;
}

void MazeWindow::processEvents() {
    sf::Event event {};

    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handleInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handleInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
        }
    }
}

void MazeWindow::update() {

}

void MazeWindow::render() {
    window.clear(BACKGROUND_COLOR);

    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    float cellWidth = windowWidth / (float) map->getNbCols();
    float cellHeight = windowHeight / (float) map->getNbRows();

    sf::RectangleShape shape(sf::Vector2f(cellWidth, cellHeight));

    shape.setOutlineThickness(0);

    for (auto iter=map->iterCell(); iter!=map->iterEnd(); iter++) {
        Position<float> cellScreenPos = Position<float>(
                (float) iter.getCol() * cellWidth,
                (float) iter.getRow() * cellHeight
                );

        shape.setPosition(cellScreenPos.getX(), cellScreenPos.getY());
        shape.setFillColor(sf::Color::Green);

        /*
        sf::Vertex line[2];
        line[0].position = sf::Vector2f(10, 0);
        line[0].color  = sf::Color::Red;
        line[1].position = sf::Vector2f(20, 0);
        line[1].color = sf::Color::Red;
         */

        window.draw(shape);
    }

    window.display();
}

void MazeWindow::handleInput(const sf::Keyboard::Key key, bool pressed) {

}
