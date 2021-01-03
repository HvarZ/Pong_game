#include <Ball.hpp>
#include <Paddle.hpp>

Ball::Ball(sf::RenderWindow *_window) noexcept : window(_window), speed_x(0), speed_y(0) {
    shape.setPosition(sf::Vector2f(400, 300));
    shape.setRadius(10);
    shape.setFillColor(sf::Color::White);
}

void Ball::move(Paddle& player_1, Paddle& player_2) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shape.setPosition(400, 300);
        speed_x = -5;
        speed_y = -5;
    }

    if (shape.getPosition().y < 0) {
        speed_y = 5;
    } else if (shape.getPosition().y > 600 - 15) {
        speed_y = -5;
    }
    if (shape.getPosition().x < 0) {
        speed_y = 5;
    }

    if (shape.getPosition().y <=  player_1.get_rectangle().getPosition().y + 5 && shape.getPosition().x <= player_1.get_rectangle().getPosition().x + 10) {
        if (shape.getPosition().y >= player_1.get_rectangle().getPosition().y - 55) {
            speed_x = 5;
        }
    }

    if (shape.getPosition().y <=  player_2.get_rectangle().getPosition().y + 5 && shape.getPosition().x >= player_2.get_rectangle().getPosition().x - 30) {
        if (shape.getPosition().y >= player_2.get_rectangle().getPosition().y - 55) {
            speed_x = -5;
        }
    }

    if (shape.getPosition().x < 0) {
        player_1.upScore();
        speed_x = 0;
        speed_y = 0;
        shape.setPosition(400, 300);
    }

    if (shape.getPosition().x > 800) {
        player_2.upScore();
        speed_x = 0;
        speed_y = 0;
        shape.setPosition(400, 300);
    }


    shape.move(speed_x, speed_y);
}

void Ball::draw() {
    window->draw(shape);
}
