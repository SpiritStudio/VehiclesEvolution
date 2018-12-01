//
// Created by SpiritStudio on 28.11.18.
//

#include <vector>

#include <Physics/Map.h>

Map::Map(b2World &world) {
    body_def_.position.Set(0.0f, 0.0f);

    body_ = world.CreateBody(&body_def_);

    b2Vec2 vertices[8];
    vertices[0].Set(0 / 60.0f, 400.0f / 60.0f);
    vertices[1].Set(50.0f / 60.0f, 370.0f / 60.0f);
    vertices[2].Set(100.0f / 60.0f, 350.0f / 60.0f);
    vertices[3].Set(400.0f / 60.0f, 300.0f / 60.0f);
    vertices[4].Set(500.0f / 60.0f, 400.0f / 60.0f);
    vertices[5].Set(550.0f / 60.0f, 500.0f / 60.0f);
    vertices[6].Set(600.0f / 60.0f, 800.0f / 60.0f);
    vertices[7].Set(0.0f, 800.0f / 60.0f);

    map_shape_.Set(vertices, 8);

    fixture_def_.shape = &map_shape_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixture_def_.density = 1.0f;

    // Override the default friction.
    fixture_def_.friction = 0.1f;

    fixture_def_.filter.categoryBits = 0x0002;
    fixture_def_.filter.maskBits = 0x0001;

    body_->CreateFixture(&fixture_def_);
}

b2Vec2 Map::getPosition() const {
    return body_->GetPosition();
}

std::vector<b2Vec2> Map::getPolyline() const {
    std::vector<b2Vec2> vertices(map_shape_.GetVertexCount());

    int32 i = 0;
    for (auto &vertex : vertices)
    {
        vertex = map_shape_.GetVertex(i);
        ++i;
    }

    return vertices;
}


double Map::getAngle() const {
    return body_->GetAngle();
}