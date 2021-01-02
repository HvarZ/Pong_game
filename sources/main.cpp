#include <Paddle.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);

    Paddle player_1(&window, 1);
    Paddle player_2(&window, 2);


    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed)
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        sf::Clock clock;

        window.setVerticalSyncEnabled(true);
        clock.restart();

        player_1.move(clock.getElapsedTime().asMilliseconds());
        player_2.move(clock.getElapsedTime().asMilliseconds());


        player_1.draw();
        player_2.draw();
        window.display();
    }

    return 0;
}
