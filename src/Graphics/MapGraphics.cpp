//
// Created by SpiritStudio on 30.11.18.
//

#include <include/Graphics/MapGraphics.h>

MapGraphics::MapGraphics() : map_graphics_(sf::LineStrip, 10){
    map_graphics_[0].position = sf::Vector2f(0, 400.0f);
    map_graphics_[1].position = sf::Vector2f(50.0f, 500.0f);
    map_graphics_[2].position = sf::Vector2f(100.0f, 400.0f);
    map_graphics_[3].position = sf::Vector2f(150.0f, 450.0f);
    map_graphics_[4].position = sf::Vector2f(200.0f, 300.0f);
    map_graphics_[5].position = sf::Vector2f(300.0f, 580.0f);
    map_graphics_[6].position = sf::Vector2f(450.0f, 500.0f);
    map_graphics_[7].position = sf::Vector2f(700.0f, 550.0f);
    map_graphics_[8].position = sf::Vector2f(720.0f, 450.0f);
    map_graphics_[9].position = sf::Vector2f(800.0f, 500.0f);
}

void MapGraphics::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(map_graphics_, states);
}
