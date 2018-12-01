//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

Physics::Physics()  : gravity_(0.0f, 9.81f),
                      world_(gravity_, false),
                      map_(world_) {
    // Temporary
    cars_.emplace_back(Car(world_, b2Vec2(6.7f, 0.0f)));
    cars_.emplace_back(Car(world_, b2Vec2(3.7f, 4.0f)));
}

void Physics::update() {
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    world_.Step(timeStep, velocityIterations, positionIterations);

    std::cout << "Body.x: " << cars_.at(0).getPosition().x <<
                 ", Body.y: " << cars_.at(0).getPosition().y <<
                 ", Body.angle" << cars_.at(0).getAngle() << std::endl;
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