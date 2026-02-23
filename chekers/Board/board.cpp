#include "board.hpp"
#include <iostream>

Board::Board(float cellSize, float offsetX, float offsetY)
        : m_cellSize(cellSize)
        , m_offsetX(offsetX)
        , m_offsetY(offsetY)
        , m_lightColor(240, 217, 181)  //цвет клеток
        , m_darkColor(181, 136, 99)
{
}

void Board::draw(sf::RenderWindow& window, const sf::Font& font) {
    drawCells(window);
    drawBorder(window);
    drawCoordinates(window, font);
}

void Board::drawCells(sf::RenderWindow& window) {
    sf::RectangleShape cell(sf::Vector2f(m_cellSize - 1, m_cellSize - 1));

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {

            if ((row + col) % 2 == 0) {
                cell.setFillColor(m_lightColor);
            } else {
                cell.setFillColor(m_darkColor);
            }


            cell.setPosition(sf::Vector2f(
                    m_offsetX + col * m_cellSize,
                    m_offsetY + row * m_cellSize
            ));

            window.draw(cell);
        }
    }
}

void Board::drawCoordinates(sf::RenderWindow& window, const sf::Font& font) {

    sf::Text text(font, "", 32);
    text.setFillColor(sf::Color::Black);

    // цифры
    for (int row = 0; row < BOARD_SIZE; ++row) {
        int rowNumber = getRowNumber(row);
        std::string rowStr = std::to_string(rowNumber);

        text.setString(rowStr);

        // Слева
        text.setPosition(sf::Vector2f(
                m_offsetX - 35,
                m_offsetY + row * m_cellSize + m_cellSize/2 - 25
        ));
        window.draw(text);

        // Справа
        text.setPosition(sf::Vector2f(
                m_offsetX + BOARD_SIZE * m_cellSize + 25,
                m_offsetY + row * m_cellSize + m_cellSize/2 - 25
        ));
        window.draw(text);
    }

    // буквы
    for (int col = 0; col < BOARD_SIZE; ++col) {
        std::string colLetter = getColumnLetter(col);
        text.setString(colLetter);

        // Сверху
        text.setPosition(sf::Vector2f(
                m_offsetX + col * m_cellSize + m_cellSize/2 - 8,
                m_offsetY - 50
        ));
        window.draw(text);

        // Снизу
        text.setPosition(sf::Vector2f(
                m_offsetX + col * m_cellSize + m_cellSize/2 - 8,
                m_offsetY + BOARD_SIZE * m_cellSize + 10
        ));
        window.draw(text);
    }
}

void Board::drawBorder(sf::RenderWindow& window) {
    sf::RectangleShape border(sf::Vector2f(
            BOARD_SIZE * m_cellSize + 2,
            BOARD_SIZE * m_cellSize + 2
    ));
    border.setPosition(sf::Vector2f(m_offsetX - 1, m_offsetY - 1));
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Black);
    border.setOutlineThickness(1);
    window.draw(border);
}


sf::Vector2f Board::getScreenPosition(int row, int col) const {
    return sf::Vector2f(
            m_offsetX + col * m_cellSize + m_cellSize / 2,
            m_offsetY + row * m_cellSize + m_cellSize / 2
    );
}

bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

std::string Board::getColumnLetter(int col) const {
    
    char letter = 'a' + col;
    return std::string(1, letter);
}

int Board::getRowNumber(int row) const {

    return BOARD_SIZE - row;
}