#include "figure_pentagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Pentagon::Pentagon() : side(0), number(5) {
    std::cin >> this->side;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Pentagon has created.-" << std::endl;}
}

double Pentagon::Square() {
    double tmp = (5 * side * side) / (4 * tan((2 * pi) / 10));
    return side < 0 ? 404 : tmp;
}
void Pentagon::Print() {
    if (side >= 0) std::cout << "Length of side is equal: " << side << ". Number of sides is " << number << "." << std::endl;
}

Pentagon::~Pentagon() {if (side >= 0) std::cout << "-Pentagon was deleted.-" << std::endl;}
