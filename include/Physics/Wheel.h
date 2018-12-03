//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_WHEEL_H
#define VEHICLESEVOLUTION_WHEEL_H

#include <Box2D/Box2D.h>

class Wheel {

public:
    Wheel(b2World &world, double radius);

    b2Vec2 getPosition() const;
    double getAngle() const;

    double getRadius() const;

    b2Body* getBody();

private:
    b2BodyDef body_def_;
    b2CircleShape dynamic_circle_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

};

#endif //VEHICLESEVOLUTION_WHEEL_H
