#include "figure_hexagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Hexagon::Hexagon() {
    this->side = 0;
}

Hexagon::Hexagon(std::istream &is) {
    is >> this->side;;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Hexagon was created.-" << std::endl;}
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
    if (side >= 0) std::cout << "Element is hexagon. Length of side is equal: " << side << ". Square is " << this->Square() << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
    os << obj.side/*<< std::endl*/;
    return os;
}
std::istream& operator>>(std::istream& is, Hexagon& obj) {
    is >> obj.side;
    if (obj.side < 0) {
        std::cout << "Input error. ";
    }
    else { std::cout << "-Hexagon was created.-" << std::endl; }
    return is;
}

Hexagon& Hexagon::operator=(const Hexagon& right) {
    if (this == &right) return *this;
    //std::cout << "Hexagon copied" << std::endl;
    side = right.side;
    return *this;
}

Hexagon::~Hexagon() {if (side >= 0) std::cout << "-Hexagon was deleted.-" << std::endl;}
