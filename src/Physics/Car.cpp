//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Car.h>

Car::Car() : position_(), is_dead_(false) {}

b2Vec3 Car::getPosition() const {
    return position_;
}

bool Car::isDead() const {
    return is_dead_;
}