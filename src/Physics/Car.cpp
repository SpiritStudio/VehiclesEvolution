//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Car.h>

Car::Car(b2World &world, const b2Vec2 &position,
         const b2Vec2 &front_wheel_offset, const b2Vec2 &rear_wheel_offset) : is_dead_(false),
                                                   car_body_(world, position),
                                                   front_wheel_(world, position + front_wheel_offset),
                                                   rear_wheel_ (world, position + rear_wheel_offset) {
    front_joint_def_.bodyA = car_body_.getBody();
    front_joint_def_.bodyB = front_wheel_.getBody();
    front_joint_def_.collideConnected = false;
    front_joint_def_.localAnchorA.Set(1.25f, 0.5f);
    front_joint_def_.localAnchorB.Set(0, 0);
    front_joint_def_.maxMotorTorque = 2.0f;
    front_joint_def_.motorSpeed = 10.0f;
    front_joint_def_.enableMotor = true;

    front_joint_ = (b2RevoluteJoint*)world.CreateJoint(&front_joint_def_);

    rear_joint_def_.bodyA = car_body_.getBody();
    rear_joint_def_.bodyB = rear_wheel_.getBody();
    rear_joint_def_.collideConnected = false;
    rear_joint_def_.localAnchorA.Set(-1.25f, 0.5f);
    rear_joint_def_.localAnchorB.Set(0, 0);
    rear_joint_def_.maxMotorTorque = 400.0f;
    rear_joint_def_.motorSpeed = 10.0f;
    rear_joint_def_.enableMotor = true;

    rear_joint_ = (b2RevoluteJoint*)world.CreateJoint(&rear_joint_def_);
}

b2Vec2 Car::getPosition() const {
    return car_body_.getPosition();
}

b2Vec2 Car::getFrontWheelPosition() const {
    return front_wheel_.getPosition();
}

b2Vec2 Car::getRearWheelPosition() const {
    return rear_wheel_.getPosition();
}

double Car::getAngle() const {
    return car_body_.getAngle();
}

bool Car::isDead() const {
    return is_dead_;
}