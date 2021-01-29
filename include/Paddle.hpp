
#ifndef GAME_PADDLE_HPP
#define GAME_PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Paddle final {
private:
    sf::RenderWindow* window_;
    sf::RectangleShape rectangle_;
    int player_;
    int score_;
    float speed_;

public:
    Paddle(sf::RenderWindow* window, int player);

    void draw() noexcept;
    void move() noexcept;

    void upScore() noexcept;
    void drawScore() const noexcept;

    [[nodiscard]] auto getRectangle() -> sf::RectangleShape;
};


#endif //GAME_PADDLE_HPP
