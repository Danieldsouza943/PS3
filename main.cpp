// Copyright 2024 Daniel Dsouza
#include "Universe.hpp"
#include "CelestialBody.hpp"

int main(int argc, char** argv) {
    double T = std::stod(argv[1]);
    double dt = std::stod(argv[2]);
    double elapsed = 0;

    // Universe and bodies
    NB::Universe u;
    cin >> u;
    cout << u;
    sf::Texture backGround;
    backGround.loadFromFile("./nbody/starfield.jpg");
    sf::Sprite background(backGround);
    background.setPosition(-SIZE/2.f, -SIZE/2.f);
    float scale = backGround.getSize().x;
    background.setScale(SIZE / scale, SIZE / scale);

    // Window and view settings
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Universe!");
    window.setFramerateLimit(30);
    sf::Event event;

    sf::View view(sf::FloatRect(-SIZE/2.f, -SIZE/2.f, SIZE, SIZE));
    window.setView(view);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {  // Event types
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            default:
                break;
            }
        }
        // Refresh and recenter window
        window.clear(sf::Color::Black);

        // Draw bodies
        window.draw(background);
        window.draw(u);
        elapsed += dt;
        if (elapsed < T) {
            u.step(dt);
        }

        window.display();
    }

    cout << u;

    return 0;
}
