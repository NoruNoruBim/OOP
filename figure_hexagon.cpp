#include "figure_hexagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Hexagon::Hexagon() : side(0), number(6) {
    std::cin >> this->side;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Hexagon has created.-" << std::endl;}
}
Hexagon::Hexagon(std::istream &is) {
    is >> this->side;
}
Hexagon::Hexagon(const Hexagon& orig) {
    std::cout << "Hexagon copy created" << std::endl;
    this->side = orig.side;
}

double Hexagon::Square() {
    double tmp = (6 * side * side) / (4 * tan((2 * pi) / 12));
    return side < 0 ? 404 : tmp;
}
void Hexagon::Print() {
    if (side >= 0) std::cout << "Length of side is equal: " << side  << ". Number of sides is " << number << "." << std::endl;
}

Hexagon::~Hexagon() {if (side >= 0) std::cout << "-Hexagon was deleted.-" << std::endl;}
