//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_CAR_H
#define VEHICLESEVOLUTION_CAR_H

#include <Box2D/Box2D.h>

class Car {

public:
    Car(b2World &world, const b2Vec2 &position);

    b2Vec2 getPosition() const;
    double getAngle() const;
    bool isDead() const;

private:
    b2BodyDef body_def_;
    b2PolygonShape dynamic_box_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

    // Wheel front_, back_;
    // CarBody car_body_;

    bool is_dead_;

};


#endif //VEHICLESEVOLUTION_CAR_H
