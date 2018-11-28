//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_CARPARAMETERS_H
#define VEHICLESEVOLUTION_CARPARAMETERS_H


#include <vector>
#include "Box2D/Box2D.h"

class CarParameters {

public:
    double frontWheelRadius, rearWheelRadius;
    std::vector<b2Vec2> carBody;
    b2Vec2 const* frontJoint, rearJoint;

};


#endif //VEHICLESEVOLUTION_CARPARAMETERS_H
