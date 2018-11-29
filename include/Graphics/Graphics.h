//
// Created by SpiritStudio on 29.11.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICS_H
#define VEHICLESEVOLUTION_GRAPHICS_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include <Physics/Physics.h>
#include <Physics/PhysicsObserver.h>

/**
 * Class implementing Singleton and Pseudo-Observer design patterns
 */

class Graphics : public PhysicsObserver {

public:
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;

    static Graphics& getInstance() {
        static Graphics graphicsInstance;
        return graphicsInstance;
    }

    void newCars(const std::vector<std::unique_ptr<Car>> &cars) override;
    void newMap(const std::unique_ptr<Map> &map) override;
    void newCarsPositions(const std::vector<std::unique_ptr<Car>> &cars) override;

    bool isWindowOpen() const;
    void handleEvents();

    void draw();

private:
    Graphics();

    //std::vector<std::unique_ptr<CarGraphics>> cars_graphics_;
    //std::unique_ptr<MapGraphics> map_graphic_;

    // temporary
    sf::RenderWindow window_;
    sf::CircleShape shape_;

};

#endif //VEHICLESEVOLUTION_GRAPHICS_H
