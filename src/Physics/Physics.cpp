//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

Physics::Physics()  : gravity_(0.0f, 0.001f),
                      world_(gravity_, false) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world_.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 10.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 2.0f);
    body_ = world_.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, -10.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body_->CreateFixture(&fixtureDef);
}

void Physics::update() {
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    getInstance().world_.Step(timeStep, velocityIterations, positionIterations);

    std::cout << "Body.x: " << getInstance().body_->GetPosition().x <<
                 ", Body.y: " << getInstance().body_->GetPosition().y << std::endl;
}

bool Physics::allDead() {
    return false;
}

void Physics::makeCars(const std::vector<CarParameters> &cars_parameters) {

}

std::unique_ptr<Car> Physics::makeCar(const CarParameters &car_parameters) {

}