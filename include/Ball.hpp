#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include <SFML/Graphics.hpp>
#include <Paddle.hpp>

class Ball final {
private:
    sf::RenderWindow* window_;
    sf::CircleShape shape_;
    float speedX_;
    float speedY_;

public:
    explicit Ball(sf::RenderWindow* window) noexcept;

    void move(Paddle& player1, Paddle& player2) noexcept;

    void draw() noexcept;
};



#endif //PONG_BALL_HPP
