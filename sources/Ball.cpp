#include <Ball.hpp>

Ball::Ball(sf::RenderWindow *_window) noexcept : window(_window) {
    shape.setPosition(sf::Vector2f(400, 300));
    shape.setSize(sf::Vector2f(30, 30));
    shape.setFillColor(sf::Color::White);
}
