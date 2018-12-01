//
// Created by SpiritStudio on 30.11.18.
//

#include <cmath>

#include <Graphics/CarGraphics.h>

CarGraphics::CarGraphics() : wheel_front_position_offset_(75.0f, 25.0f),
                             wheel_rear_position_offset_(-75.0f, 25.0f) {
    car_body_graphics_.setPointCount(4);
    car_body_graphics_.setOrigin(sf::Vector2f(75.0f, 25.0f));
    car_body_graphics_.setPoint(0, sf::Vector2f(0.0f, 0.0f));
    car_body_graphics_.setPoint(1, sf::Vector2f(150.0f, 0.0f));
    car_body_graphics_.setPoint(2, sf::Vector2f(150.0f, 50.0f));
    car_body_graphics_.setPoint(3, sf::Vector2f(0.0f, 50.0f));
    car_body_graphics_.setFillColor(sf::Color::Red);
    car_body_graphics_.setPosition(0.0f, 0.0f);

    wheel_rear_.setRadius(30.0f);
    wheel_rear_.setOrigin(30.0f, 30.0f);
    wheel_rear_.setPosition(wheel_rear_position_offset_);
    wheel_rear_.setFillColor(sf::Color::Green);

    wheel_front_.setRadius(30.0f);
    wheel_front_.setOrigin(30.0f, 30.0f);
    wheel_front_.setPosition(wheel_front_position_offset_);
    wheel_front_.setFillColor(sf::Color::Green);
}

void CarGraphics::setPositionAndAngle(const sf::Vector2f &position, float angle) {
    setPosition(position);
    setAngle(angle);
}

void CarGraphics::setPosition(const sf::Vector2f &position) {
    car_body_graphics_.setPosition(position);
    wheel_front_.setPosition(position + wheel_front_position_offset_);
    wheel_rear_.setPosition(position + wheel_rear_position_offset_);
}

void CarGraphics::setAngle(float angle) {
    car_body_graphics_.setRotation(angle);
}

void CarGraphics::setFrontWheelPosition(const sf::Vector2f &position) {
    wheel_front_.setPosition(position);
}

void CarGraphics::setRearWheelPosition(const sf::Vector2f &position) {
    wheel_rear_.setPosition(position);
}

void CarGraphics::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(car_body_graphics_, states);
    target.draw(wheel_front_, states);
    target.draw(wheel_rear_, states);
}