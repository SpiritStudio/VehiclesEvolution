//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

Physics::Physics()  : gravity_(0.0f, 9.81f),
                      world_(gravity_, false),
                      map_(world_) {
    std::vector<CarParameters> cars_parameters;
    cars_parameters.emplace_back();

    makeCars(cars_parameters);
}

void Physics::update() {
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    world_.Step(timeStep, velocityIterations, positionIterations);
}

bool Physics::allDead() {
    return false;
}

void Physics::notifyCars() {
    Graphics::getInstance().newCars(cars_);
}

void Physics::notifyMap() {
    Graphics::getInstance().newMap(map_);
}

void Physics::notifyCarsPositions() {
    Graphics::getInstance().newCarsPositions(cars_);
}

void Physics::makeCars(const std::vector<CarParameters> &cars_parameters) {
    for (const auto &car_parameter : cars_parameters)
    {
        cars_.emplace_back(world_, b2Vec2(10.0f, 0.0f), car_parameter);
    }
}

const std::vector<Car>& Physics::getCars() {
    return cars_;
}

const Map& Physics::getMap() {
    return map_;
}

const Car& Physics::makeCar(const CarParameters &car_parameters) {

}