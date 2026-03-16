#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mi juego en SFML");
    sf::CircleShape circle(200.f);
    circle.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        // aquí dibujás
        window.display();
    }
}
