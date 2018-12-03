//
// Created by SpiritStudio on 30.11.18.
//

#ifndef VEHICLESEVOLUTION_CARGRAPHICS_H
#define VEHICLESEVOLUTION_CARGRAPHICS_H


#include <SFML/Graphics.hpp>

class CarGraphics : public sf::Drawable {

public:
    CarGraphics(const std::vector<sf::Vector2f> &vertices, double front_wheel_radius, double rear_wheel_radius);

    void setPositionAndAngle(const sf::Vector2f &position, float angle);
    void setFrontWheelPosition(const sf::Vector2f &position);
    void setRearWheelPosition(const sf::Vector2f &position);


private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPosition(const sf::Vector2f &position);
    void setAngle(float angle);

    sf::ConvexShape car_body_graphics_;
    sf::CircleShape wheel_rear_;
    sf::CircleShape wheel_front_;

};


#endif //VEHICLESEVOLUTION_CARGRAPHICS_H
