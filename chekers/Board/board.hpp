#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Board {
public:
    Board(float cellSize, float offsetX, float offsetY);

    void draw(sf::RenderWindow& window, const sf::Font& font);


    sf::Vector2f getScreenPosition(int row, int col) const;
    bool isValidPosition(int row, int col) const;

private:
    static const int BOARD_SIZE = 8;

    float m_cellSize;
    float m_offsetX;
    float m_offsetY;

    sf::Color m_lightColor;
    sf::Color m_darkColor;

    void drawCells(sf::RenderWindow& window);
    void drawCoordinates(sf::RenderWindow& window, const sf::Font& font);
    void drawBorder(sf::RenderWindow& window);

    std::string getColumnLetter(int col) const;
    int getRowNumber(int row) const;
};

#endif