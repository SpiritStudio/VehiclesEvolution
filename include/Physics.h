//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_PHYSICS_H
#define VEHICLESEVOLUTION_PHYSICS_H

//Box2D files
#include <Box2D/Box2D.h>

// Standard library files
#include <vector>
#include <memory>
#include <iostream>

// Project files
#include <Car.h>
#include <Map.h>
#include <CarParameters.h>

/**
 * Class implementing Factory and Singleton design patterns
 */

class Physics {

public:
    Physics(const Physics&) = delete;
    Physics& operator=(const Physics&) = delete;

    static Physics& getInstance() {
        static Physics physicsInstance;
        return physicsInstance;
    }

    static void update();
    static bool allDead();

    static void makeCars(const std::vector<CarParameters> &cars_parameters);

private:
    Physics();

    static std::unique_ptr<Car> makeCar(const CarParameters &car_parameters);

    b2Vec2 gravity_;
    b2World world_;
    std::vector<std::unique_ptr<Car>> cars_;
    std::unique_ptr<Map> map_;

    // temporary
    b2Body* body_;
};

#endif //VEHICLESEVOLUTION_PHYSICS_H
