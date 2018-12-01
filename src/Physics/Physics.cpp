//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

Physics::Physics()  : gravity_(0.0f, 9.81f),
                      world_(gravity_, false),
                      map_(world_) {
    // Temporary
    cars_.emplace_back(Car(world_, b2Vec2(5.7f, 1.0f),
                       b2Vec2(75.0f/60.0f, 25.0f/60.0f), b2Vec2(-75.0f/60.0f, 25.0f/60.0f)));
    cars_.emplace_back(Car(world_, b2Vec2(3.7f, 4.0f),
                       b2Vec2(75.0f/60.0f, 25.0f/60.0f), b2Vec2(-75.0f/60.0f, 25.0f/60.0f)));
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

void Physics::notifyCars(PhysicsObserver &observer) {
    observer.newCars(cars_);
}

void Physics::notifyMap(PhysicsObserver &observer) {
    observer.newMap(map_);
}

void Physics::notifyCarsPositions(PhysicsObserver &observer) {
    observer.newCarsPositions(cars_);
}

void Physics::makeCars(const std::vector<CarParameters> &cars_parameters) {

}

const std::vector<Car>& Physics::getCars() {
    return cars_;
}

const Map& Physics::getMap() {
    return map_;
}

const Car& Physics::makeCar(const CarParameters &car_parameters) {

}