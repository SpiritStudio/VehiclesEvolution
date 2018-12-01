//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Car.h>

Car::Car(b2World &world) : is_dead_(false) {
    bodyDef_.type = b2_dynamicBody;
    bodyDef_.position.Set(0.0f, 2.0f);
    body_ = world.CreateBody(&bodyDef_);

    dynamicBox_.SetAsBox(3.0f, 1.0f);
    fixtureDef_.shape = &dynamicBox_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef_.density = 1.0f;

    // Override the default friction.
    fixtureDef_.friction = 0.3f;

    // Add the shape to the body.
    body_->CreateFixture(&fixtureDef_);
}

b2Vec2 Car::getPosition() const {
    return body_->GetPosition();
}

double Car::getAngle() const {
    return body_->GetAngle();
}

bool Car::isDead() const {
    return is_dead_;
}