// Copyright 2024 Daniel Dsouza
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <memory>
#include <utility>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using std::cout, std::cin, std::endl;

namespace NB {

class CelestialBody : public sf::Drawable {
 private:
    friend class Universe;
    double x, y, xv, yv, _mass, scale;
    std::string name;
    sf::Texture texture;
    friend std::istream& operator>>(std::istream& is, CelestialBody& c);
    friend std::ostream& operator<<(std::ostream& os, const CelestialBody& c);

 protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

 public:
    explicit CelestialBody(float);
    ~CelestialBody() = default;
    sf::Vector2f position() const { return sf::Vector2f(x, y); }
    sf::Vector2f velocity() const { return sf::Vector2f(xv, yv); }
    double mass() const { return _mass; }
    void velocityUpdater(double fx, double fy, double dt);
    void positionUpdater(double dt);
};

}  // namespace NB
