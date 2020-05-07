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
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    shape.setPosition(200, 300);

    window.clear();
    window.draw(shape);
    window.display();
}

void MazeWindow::handleInput(const sf::Keyboard::Key key, bool pressed) {

}
