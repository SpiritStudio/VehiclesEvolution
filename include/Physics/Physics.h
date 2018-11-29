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
#include <Physics/Car.h>
#include <Physics/Map.h>
#include <Physics/PhysicsObserver.h>
#include <EvolutionaryAlgorithm/CarParameters.h>


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

    void update();
    bool allDead();

    void makeCars(const std::vector<CarParameters> &cars_parameters);

    void notifyCars(PhysicsObserver &observer);
    void notifyMap(PhysicsObserver &observer);
    void notifyCarsPositions(PhysicsObserver &observer);

    const std::vector<std::unique_ptr<Car>>& getCars();
    const std::unique_ptr<Map>& getMap();

private:
    Physics();

    std::unique_ptr<Car> makeCar(const CarParameters &car_parameters);

    b2Vec2 gravity_;
    b2World world_;
    std::vector<std::unique_ptr<Car>> cars_;
    std::unique_ptr<Map> map_;

    // temporary
    b2Body* body_;
};

#endif //VEHICLESEVOLUTION_PHYSICS_H
