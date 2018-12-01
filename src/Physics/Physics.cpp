//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

Physics::Physics()  : gravity_(0.0f, 9.81f),
                      world_(gravity_, false) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world_.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 1.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 10.0f);

    // Temporary
    cars_.emplace_back(Car(world_));
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
                 ", Body.y: " << cars_.at(0).getPosition().y << std::endl;
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