// Copyright 2024 Daniel Dsouza
#pragma once
#include <vector>
#include <memory>
#include <cmath>
#include "CelestialBody.hpp"

using std::cout, std::cin, std::endl;

namespace NB {

#define SIZE 800
#define G_C 6.67e-11

class Universe : public sf::Drawable {
 private:
    int n;
    double r, scale;
    std::vector<std::shared_ptr<CelestialBody>> bodys;

 protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

 public:
    Universe() = default;
    ~Universe() = default;
    int numPlanets() const { return n; }
    double radius() const { return r; }
    CelestialBody& operator[](int i) { return *bodys[i]; }
    void step(double);

    friend std::istream &operator>>(std::istream &is, Universe &u);
    friend std::ostream &operator<<(std::ostream &os, const Universe &u);
};

}  // namespace NB
