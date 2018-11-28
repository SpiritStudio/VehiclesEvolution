//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_CAR_H
#define VEHICLESEVOLUTION_CAR_H

#include <Box2D/Box2D.h>

class Car {

public:
    Car();

    b2Vec3 getPosition() const;
    bool isDead() const;

private:
    b2Vec3 position_;

    // Wheel front_, back_;
    // CarBody car_body_;

    bool is_dead_;

};


#endif //VEHICLESEVOLUTION_CAR_H
