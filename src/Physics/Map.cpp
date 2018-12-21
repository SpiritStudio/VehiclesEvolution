//
// Created by SpiritStudio on 28.11.18.
//

#include <vector>
#include <fstream>

#include <mapbox/earcut.h>

#include <Physics/Map.h>


Map::Map(b2World &world) {
    body_def_.position.Set(0.0f, 0.0f);

    body_ = world.CreateBody(&body_def_);
    // TODO WRAP TRIANGULATION INTO SEPARATE METHOD
    // MAYBE PARAMETERS - POLYLINE, RETURNS VECTOR OF FIXTURE_DEF?
    // TODO READ MAP FROM FILE
    loadFromFile("data/map.txt");

    // The number type to use for tessellation
    using Coord = double;
    using N = uint32_t;
    using Point = std::array<Coord, 2>;
    std::vector<std::vector<Point>> polygon;
    std::vector<Point> points;

    for (const auto &point : polyline_)
    {
        points.push_back({point.x, point.y});
    }


    polygon.push_back(points);

    std::vector<N> indices = mapbox::earcut<N>(polygon);

    if (indices.size() % 3 != 0)
    {
        throw std::runtime_error("Ear cutting algorithm failed!");
    }

    unsigned long i = 0;

    for (auto it = indices.begin(); it != indices.end(); it += 3)
    {
        map_shape_.emplace_back();
        fixture_def_.emplace_back();

        b2Vec2 triangle[3];
        Point point = points.at(*it);
        triangle[0] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));
        point = points.at(*(it+1));
        triangle[1] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));
        point = points.at(*(it+2));
        triangle[2] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));

        map_shape_.at(i).Set(triangle, 3);

        fixture_def_.at(i).shape = &map_shape_.at(i);

        // Set the box density to be non-zero, so it will be dynamic.
        fixture_def_.at(i).density = 1.0f;

        // Override the default friction.
        fixture_def_.at(i).friction = 0.1f;

        fixture_def_.at(i).filter.categoryBits = 0x0002;
        fixture_def_.at(i).filter.maskBits = 0x0001;

        body_->CreateFixture(&fixture_def_.at(i));
    }
}

b2Vec2 Map::getPosition() const {
    return body_->GetPosition();
}

std::vector<b2Vec2> Map::getPolyline() const {
    return polyline_;
}

double Map::getAngle() const {
    return body_->GetAngle();
}

void Map::loadFromFile(std::string filename) {
    std::ifstream input(filename);

    polyline_.clear();

    double x, y;

    while (input >> x >> y)
    {
        polyline_.emplace_back(x, y);
    }
}