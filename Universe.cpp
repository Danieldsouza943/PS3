// Copyright 2024 Daniel Dsouza
#include "Universe.hpp"

namespace NB {

std::istream& operator>>(std::istream& is, Universe& u) {
    is >> u.n;
    is >> u.r;
    u.scale = SIZE / (u.r * 2);
    for (int i = 0; i < u.n; i++) {
        std::shared_ptr<CelestialBody> body =
        std::make_shared<CelestialBody>(u.scale);
        is >> *body;
        u.bodys.push_back(body);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Universe& u) {
    os << u.n << "\n" << u.r << "\n";
    for (auto& body : u.bodys) {
        os << *body;
    }
    return os;
}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto& body : bodys) {
        target.draw(*body);
    }
}

void Universe::step(double dt) {
    for (auto &body : bodys) {
        double fx = 0, fy = 0;
        for (auto &other : bodys) {
            if (&body == &other)
                continue;
            double dx = other->position().x - body->position().x;
            double dy = other->position().y - body->position().y;
            double dist = sqrt(dx * dx + dy * dy);
            double force = G_C * body->mass() * other->mass() / (dist * dist);
            fx += force * dx / dist;
            fy += force * dy / dist;
        }
        body->velocityUpdater(fx, fy, dt);
    }

    std::for_each(bodys.begin(), bodys.end(), [this, &dt]
    (std::shared_ptr<CelestialBody> &bodyPtr) { bodyPtr->positionUpdater(dt); });
}

}  // namespace NB
