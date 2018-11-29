//
// Created by SpiritStudio on 29.11.18.
//

#include <Graphics/Graphics.h>

Graphics::Graphics() : window_(sf::VideoMode(200, 200), "Vehicles Evolution Simulation"),
                       shape_(100.0f) {
    shape_.setFillColor(sf::Color::Red);
}

void Graphics::newCars(const std::vector<std::unique_ptr<Car>> &cars) {
    std::cout << "Notifying new Cars" << std::endl;
}

void Graphics::newMap(const std::unique_ptr<Map> &map) {
    std::cout << "Notifying new Map" << std::endl;
}

void Graphics::newCarsPositions(const std::vector<std::unique_ptr<Car>> &cars) {
    std::cout << "Notifying new Cars Positions" << std::endl;
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
    window_.draw(shape_);
    window_.display();
}