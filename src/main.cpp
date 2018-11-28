//
// Created by SpiritStudio on 20.11.18.
//

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <Physics.h>

int main()
{
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

        Physics::getInstance().update();

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}