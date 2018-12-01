//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Car.h>

Car::Car(b2World &world) : is_dead_(false) {
    body_def_.type = b2_dynamicBody;
    body_def_.position.Set(6.7f, 0.0f);
    body_ = world.CreateBody(&body_def_);

    dynamic_box_.SetAsBox(1.25f, 0.4f);
    fixture_def_.shape = &dynamic_box_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixture_def_.density = 1.0f;

    // Override the default friction.
    fixture_def_.friction = 0.1f;

    // Add the shape to the body.
    body_->CreateFixture(&fixture_def_);
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