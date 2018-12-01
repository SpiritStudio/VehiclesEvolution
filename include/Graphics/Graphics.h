//
// Created by SpiritStudio on 29.11.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICS_H
#define VEHICLESEVOLUTION_GRAPHICS_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include <Physics/Physics.h>
#include <Physics/PhysicsObserver.h>

#include <Graphics/CarGraphics.h>
#include <Graphics/MapGraphics.h>

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

    void newCars(const std::vector<Car> &cars) override;
    void newMap(const Map &map) override;
    void newCarsPositions(const std::vector<Car> &cars) override;

    bool isWindowOpen() const;
    void handleEvents();

    void ensureConstantFrameRate();
    void restartClock();

    void draw();

private:
    Graphics();

    static constexpr float PIXELS_PER_METER_ = 60.0f;

    std::vector<CarGraphics> cars_graphics_;
    MapGraphics map_graphic_;

    sf::RenderWindow window_;
    sf::Clock clock_;
    sf::Time time_;

};

#endif //VEHICLESEVOLUTION_GRAPHICS_H