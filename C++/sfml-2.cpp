#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Testing");
    CircleShape circle(200.f);
}
