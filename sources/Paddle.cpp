#include <Paddle.hpp>

Paddle::Paddle(sf::RenderWindow *_window, int _player)
                : window(_window), y(300), score(0), player(_player), speed(5) {
    rectangle.setSize(sf::Vector2f(10, 100));
    rectangle.setOrigin(5, 50);

    if (player == 1) {
        rectangle.setPosition(25, static_cast<float>(y));
    } else {
        rectangle.setPosition(775, static_cast<float>(y));
    }
}

void Paddle::draw() {
    window->draw(rectangle);
}

void Paddle::move() {
    if (player != 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rectangle.getPosition().y > 50) {
            rectangle.move(0, -speed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rectangle.getPosition().y < 550) {
            rectangle.move(0, speed);
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && rectangle.getPosition().y > 50) {
            rectangle.move(0, -speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && rectangle.getPosition().y < 550) {
            rectangle.move(0, speed);
        }
    }

}

void Paddle::upScore() noexcept {
    score++;
}

auto Paddle::get_rectangle() -> sf::RectangleShape {
    return rectangle;
}