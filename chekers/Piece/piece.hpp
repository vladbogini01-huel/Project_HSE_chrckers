#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

class Piece {
private:
    std::string color;
    std::string type;

public:
    Piece() : color("empty"), type("man") {}
    Piece(std::string c) : color(c), type("man") {}
    Piece(std::string c, std::string t) : color(c), type(t) {}

    std::string getColor() const { return color; }
    std::string getType() const { return type; }

    bool isEmpty() const { return color == "empty"; }
    bool isKing() const { return type == "king"; }
    bool isWhite() const { return color == "white"; }
    bool isBlack() const { return color == "black"; }

    void makeEmpty() { color = "empty"; type = "man"; }
    void promoteToKing() { if (!isEmpty()) type = "king"; }

    char getSymbol() const {
        if (color == "white") return (type == "king") ? 'W' : 'w';
        if (color == "black") return (type == "king") ? 'B' : 'b';
        return '.';
    }
};

#endif