//
// Created by SpiritStudio on 29.11.18.
//

#include <Graphics/Graphics.h>

Graphics::Graphics() : window_(sf::VideoMode(800, 600), "Vehicles Evolution Simulation"),
                       clock_() {

}

void Graphics::newCars(const std::vector<Car> &cars) {
    cars_graphics_.clear();

    for (const auto &car : cars)
    {
        cars_graphics_.emplace_back(CarGraphics());
    }
}

void Graphics::newMap(const Map &map) {
    auto polyline = map.getPolyline();

    map_graphic_.resetPolyline(polyline.size());

    int i = 0;
    for (const auto &vertex : polyline)
    {
        map_graphic_.setVertex(i, sf::Vector2f(PIXELS_PER_METER_ * vertex.x, PIXELS_PER_METER_ * vertex.y));
        ++i;
    }
}

void Graphics::newCarsPositions(const std::vector<Car> &cars) {
    int i = 0;
    for (const auto &car : cars)
    {
        auto angle = static_cast<float>(car.getAngle() * 180.0f / M_PI);
        sf::Vector2f position = sf::Vector2f(PIXELS_PER_METER_ * car.getPosition().x,
                                             PIXELS_PER_METER_ * car.getPosition().y);
        cars_graphics_.at(i).setPositionAndAngle(position, angle);

        sf::Vector2f front_wheel_position = sf::Vector2f(PIXELS_PER_METER_ * car.getFrontWheelPosition().x,
                                                         PIXELS_PER_METER_ * car.getFrontWheelPosition().y);
        cars_graphics_.at(i).setFrontWheelPosition(front_wheel_position);

        sf::Vector2f rear_wheel_position = sf::Vector2f(PIXELS_PER_METER_ * car.getRearWheelPosition().x,
                                                         PIXELS_PER_METER_ * car.getRearWheelPosition().y);
        cars_graphics_.at(i).setRearWheelPosition(rear_wheel_position);

        ++i;
    }
}

bool Graphics::isWindowOpen() const {
    return window_.isOpen();
}

void Graphics::handleEvents() {
    sf::Event event;
    while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_.close();
    }
}

void Graphics::draw() {
    window_.clear();

    window_.draw(map_graphic_);

    for (const auto &car_graphics : cars_graphics_)
    {
        window_.draw(car_graphics);
    }

    window_.display();
}

void Graphics::ensureConstantFrameRate() {
    time_ = clock_.restart();
    sf::Time time_for_sleep = sf::milliseconds(17) - time_;
    sf::sleep(time_for_sleep);
    time_ = clock_.restart();
}

void Graphics::restartClock() {
    time_ = clock_.restart();
}