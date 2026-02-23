#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board/board.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 800)), "checkers");


    sf::Font font;

    std::vector<std::string> fontPaths = {
            "/Users/vdadislavbogini/CLionProjects/chekers/BelweC AG Bold.ttf"

    };

    bool fontLoaded = false;
    for (const auto& path : fontPaths) {
        if (font.openFromFile(path)) {
            fontLoaded = true;
            break;
        }
    }

    if (!fontLoaded) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return -1;
    }


    Board board(80.0f, 80.0f, 80.0f);


    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        board.draw(window, font);

        window.display();
    }

    return 0;
}