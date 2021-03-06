#include <Paddle.hpp>
#include <Ball.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(45);

    Paddle player_1(&window, 1);
    Paddle player_2(&window, 2);

    Ball ball(&window);


    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed)
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        player_1.move();
        player_2.move();
        ball.move(player_1, player_2);

        player_1.draw();
        player_1.drawScore();

        player_2.draw();
        player_2.drawScore();

        ball.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}