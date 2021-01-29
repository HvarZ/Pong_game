#include <Paddle.hpp>

Paddle::Paddle(sf::RenderWindow *window, int _player_)
                : window_(window), score_(0), player_(_player_), speed_(5) {
    rectangle_.setSize(sf::Vector2f(10, 100));
    rectangle_.setOrigin(5, 50);

    if (player_ == 1) {
        rectangle_.setPosition(25, 300);
    } else {
        rectangle_.setPosition(775, 300);
    }
}


void Paddle::draw() noexcept {
    window_->draw(rectangle_);
}

void Paddle::move() noexcept {
    if (player_ != 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rectangle_.getPosition().y > 50) {
            rectangle_.move(0, -speed_);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rectangle_.getPosition().y < 550) {
            rectangle_.move(0, speed_);
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && rectangle_.getPosition().y > 50) {
            rectangle_.move(0, -speed_);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && rectangle_.getPosition().y < 550) {
            rectangle_.move(0, speed_);
        }
    }

}

void Paddle::upScore() noexcept {
    score_++;
}

auto Paddle::getRectangle() -> sf::RectangleShape {
    return rectangle_;
}

void Paddle::drawScore() const noexcept {
    sf::Font font;
    font.loadFromFile("../fonts/Impact_Regular.ttf");

    sf::Text score_text("", font);
    score_text.setString(std::to_string(score_));
    score_text.setCharacterSize(30);
    score_text.setFillColor(sf::Color::White);

    if (player_ != 1) {
        score_text.setPosition(sf::Vector2f(350, 0));
    } else {
        score_text.setPosition(sf::Vector2f(450, 0));
    }

    window_->draw(score_text);
}

