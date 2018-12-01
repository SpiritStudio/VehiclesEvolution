//
// Created by SpiritStudio on 01.12.18.
//

#include <Physics/Wheel.h>

Wheel::Wheel(b2World &world, const b2Vec2 &position) {
    body_def_.type = b2_dynamicBody;
    body_def_.position.Set(position.x, position.y);
    body_ = world.CreateBody(&body_def_);

    dynamic_circle_.m_radius = 0.5;
    fixture_def_.shape = &dynamic_circle_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixture_def_.density = 1.0f;

    // Override the default friction.
    fixture_def_.friction = 0.1f;

    fixture_def_.filter.categoryBits = 0x0001;
    fixture_def_.filter.maskBits = 0x0002;

    // Add the shape to the body.
    body_->CreateFixture(&fixture_def_);
}

b2Body* Wheel::getBody() {
    return body_;
}

b2Vec2 Wheel::getPosition() const {
    return body_->GetPosition();
}

double Wheel::getAngle() const {
    return body_->GetAngle();
}