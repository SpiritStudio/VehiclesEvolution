//
// Created by SpiritStudio on 30.11.18.
//

#ifndef VEHICLESEVOLUTION_MAPGRAPHICS_H
#define VEHICLESEVOLUTION_MAPGRAPHICS_H


#include <SFML/Graphics.hpp>

class MapGraphics : public sf::Drawable {

public:
    MapGraphics();

    void setPosition(const sf::Vector2f &position);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::VertexArray map_graphics_;

};


#endif //VEHICLESEVOLUTION_MAPGRAPHICS_H
