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

    for (auto iter = map->iterCell(); iter != map->iterEnd(); iter++) {
        shape.setPosition(iter.getCol()*cellWidth, iter.getRow()*cellHeight);
        shape.setFillColor(sf::Color::Green);

        window.draw(shape);
    }

    const float thickness = 5;

    sf::RectangleShape line(sf::Vector2f(cellWidth + thickness, thickness));
    line.setFillColor(sf::Color::Red);

    for (auto iter = map->iterWallHoriz(); iter != map->iterEnd(); iter++) {
        if (iter.getWall()->isFilled()) {
            float x = cellWidth * iter.getCol() - thickness/2;
            float y = cellHeight * ceilf(iter.getRow()) - thickness/2;

            line.setPosition(sf::Vector2f(x, y));
            window.draw(line);
        }
    }

    line.setSize(sf::Vector2f(thickness, cellHeight + thickness));

    for (auto iter = map->iterWallVert(); iter != map->iterEnd(); iter++) {
        if (iter.getWall()->isFilled()) {
            float x = cellWidth * ceilf(iter.getCol()) - thickness/2;
            float y = cellHeight * iter.getRow() - thickness/2;

            line.setPosition(sf::Vector2f(x, y));
            window.draw(line);
        }
    }

    window.display();
}

void MazeWindow::handleInput(const sf::Keyboard::Key key, bool pressed) {

}
