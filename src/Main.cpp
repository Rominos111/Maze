#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include "../headers/env/Map.h"
#include "../headers/view/MapTerm.h"

int main(int argc, char **argv) {
    setenv("DISPLAY", "127.0.0.1:0", true);

    Map map(3, 5);

    displayMapToTerm(&map);

    /*
    std::cout << "test 1" << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
     */

    return EXIT_SUCCESS;
}

// EXIT_FAILURE
// https://stackoverflow.com/questions/9386266/overloading-the-operator-to-increment-an-iterator