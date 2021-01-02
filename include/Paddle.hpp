
#ifndef GAME_PADDLE_HPP
#define GAME_PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Paddle final {
private:
    sf::RenderWindow* window;
    sf::RectangleShape rectangle;
    double y;
    int player;
    int score;
    float speed;

public:
    Paddle(sf::RenderWindow* _window, int player);

    void draw();
    void move(float time);

    void upScore() noexcept;
};


#endif //GAME_PADDLE_HPP
