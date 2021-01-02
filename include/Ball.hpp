#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::RenderWindow* window;
    sf::RectangleShape shape;
    int x;
    int y;

public:
    explicit Ball(sf::RenderWindow* _window) noexcept;


};



#endif //PONG_BALL_H
