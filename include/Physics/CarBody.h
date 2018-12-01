//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_CARBODY_H
#define VEHICLESEVOLUTION_CARBODY_H

#include <Box2D/Box2D.h>

class CarBody {

public:
    CarBody(b2World &world, const b2Vec2 &position);

    b2Vec2 getPosition() const;
    double getAngle() const;

    b2Body* getBody();

private:
    b2BodyDef body_def_;
    b2PolygonShape dynamic_box_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_CARBODY_H
