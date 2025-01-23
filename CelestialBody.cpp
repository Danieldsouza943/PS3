// Copyright 2024 Daniel Dsouza
#include "CelestialBody.hpp"

namespace sf { sf::Vector2f flipped(sf::Vector2f v)
{ return sf::Vector2f(v.x, -v.y); } }

namespace NB {

CelestialBody::CelestialBody(float scale) : scale(scale) {}

std::istream& operator>>(std::istream& is, CelestialBody& c) {
    is >> c.x >> c.y >> c.xv >> c.yv >> c._mass >> c.name;
    std::string path = "./nbody/" + c.name;
    if (!c.texture.loadFromFile(path)) {
        std::cerr << "Unable to load texture " << path << std::endl;
        // exit(1);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const CelestialBody& c) {
    os << c.x << " " << c.y << " " << c.xv << " "
    << c.yv << " " << c._mass << " " << c.name << std::endl;
    return os;
}

void CelestialBody::draw(sf::RenderTarget &target,
sf::RenderStates states) const {
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setPosition(x * scale, y * scale);
    sprite.setPosition(sf::flipped(sprite.getPosition()));
    target.draw(sprite);
}

void CelestialBody::velocityUpdater(double fx, double fy, double dt) {
    double ax = fx / _mass;
    double ay = fy / _mass;

    xv += ax * dt;
    yv += ay * dt;
}

void CelestialBody::positionUpdater(double dt) {
    x += xv * dt;
    y += yv * dt;
}

}  // namespace NB
