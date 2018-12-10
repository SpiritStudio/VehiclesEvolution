//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_MAP_H
#define VEHICLESEVOLUTION_MAP_H

#include <Box2D/Box2D.h>

class Map {

public:
    Map(b2World &world);

    b2Vec2 getPosition() const;
    double getAngle() const;
    std::vector<b2Vec2> getPolyline() const;

private:
    b2BodyDef body_def_;
    std::vector<b2PolygonShape> map_shape_;
    std::vector<b2FixtureDef> fixture_def_;
    std::vector<b2Vec2> polyline_;
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_MAP_H
