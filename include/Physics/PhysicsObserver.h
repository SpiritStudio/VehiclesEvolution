//
// Created by SpiritStudio on 29.11.18.
//

#ifndef VEHICLESEVOLUTION_PHYSICSOBSERVER_H
#define VEHICLESEVOLUTION_PHYSICSOBSERVER_H

#include <memory>
#include <vector>

#include <Physics/Car.h>
#include <Physics/Map.h>

class PhysicsObserver {
public:
    explicit PhysicsObserver() = default;

    virtual void newCars(const std::vector<Car> &cars) = 0;
    virtual void newMap(const Map &map) = 0;
    virtual void newCarsPositions(const std::vector<Car> &cars) = 0;
};


#endif //VEHICLESEVOLUTION_PHYSICSOBSERVER_H
