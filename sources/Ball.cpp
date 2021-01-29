#include <Ball.hpp>
#include <Paddle.hpp>

Ball::Ball(sf::RenderWindow* window) noexcept : window_(window), speedX_(0), speedY_(0) {
    shape_.setPosition(sf::Vector2f(400, 300));
    shape_.setRadius(10);
    shape_.setFillColor(sf::Color::White);
}

void Ball::move(Paddle& player1, Paddle& player2) noexcept {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shape_.setPosition(400, 300);
        speedX_ = -5;
        speedY_ = -5;
    }

    if (shape_.getPosition().y < 0) {
        speedY_ = 5;
    } else if (shape_.getPosition().y > 600 - 15) {
        speedY_ = -5;
    }
    if (shape_.getPosition().x < 0) {
        speedY_ = 5;
    }

    if (shape_.getPosition().y <=  player1.getRectangle().getPosition().y + 5 && shape_.getPosition().x <= player1.getRectangle().getPosition().x + 10) {
        if (shape_.getPosition().y >= player1.getRectangle().getPosition().y - 55) {
            speedX_ = 5;
        }
    }

    if (shape_.getPosition().y <=  player2.getRectangle().getPosition().y + 5 && shape_.getPosition().x >= player2.getRectangle().getPosition().x - 30) {
        if (shape_.getPosition().y >= player2.getRectangle().getPosition().y - 55) {
            speedX_ = -5;
        }
    }

    if (shape_.getPosition().x < 0) {
        player1.upScore();
        speedX_ = 0;
        speedY_ = 0;
        shape_.setPosition(400, 300);
    }

    if (shape_.getPosition().x > 800) {
        player2.upScore();
        speedX_ = 0;
        speedY_ = 0;
        shape_.setPosition(400, 300);
    }


    shape_.move(speedX_, speedY_);
}

void Ball::draw() noexcept {
    window_->draw(shape_);
}
