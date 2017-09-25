#include "figure_octagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Octagon::Octagon() : side(0), number(8) {
    std::cin >> this->side;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Octagon has created.-" << std::endl;}
}

double Octagon::Square() {
    double tmp = (8 * side * side) / (4 * tan((2 * pi) / 16));
    return side < 0 ? 404 : tmp;
}
void Octagon::Print() {
    if (side >= 0) std::cout << "Length of side is equal: " << side << ". Number of sides is " << number << "." << std::endl;
}

Octagon::~Octagon() {if (side >= 0) std::cout << "-Octagon was deleted.-" << std::endl;}
