#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include <SFML/Graphics.hpp>
#include <Paddle.hpp>

class Ball final {
private:
    sf::RenderWindow* window;
    sf::CircleShape shape;
    float speed_x;
    float speed_y;

public:
    explicit Ball(sf::RenderWindow* _window) noexcept;

    void move(Paddle& player_1, Paddle& player_2) noexcept;

    void draw() noexcept;
};



#endif //PONG_BALL_HPP
