#include "figure_octagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Octagon::Octagon() {
    this->side = 0;
}

Octagon::Octagon(std::istream &is) {
    std::cout << "Length:" << std::endl;
	is >> this->side;;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Octagon was created.-" << std::endl;}
}

Octagon::Octagon(const Octagon& orig) {
    std::cout << "Octagon copy created" << std::endl;
    this->side = orig.side;
}

double Octagon::Square() {
    double tmp = (8 * side * side) / (4 * tan((2 * pi) / 16));
    return side < 0 ? 404 : tmp;
}
void Octagon::Print() {
    if (side >= 0) std::cout << "Element is octagon. Length of side is equal: " << side << ". Square is " << this->Square() << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj) {
    os << obj.side/*<< std::endl*/;
    return os;
}
std::istream& operator>>(std::istream& is, Octagon& obj) {
    is >> obj.side;
    if (obj.side < 0) {
        std::cout << "Input error. ";
    }
    else { std::cout << "-Octagon was created.-" << std::endl; }
    return is;
}

Octagon& Octagon::operator=(const Octagon& right) {
    if (this == &right) return *this;
    //std::cout << "Octagon copied" << std::endl;
    side = right.side;
    return *this;
}

Octagon::~Octagon() {std::cout << "-Octagon was deleted.-" << std::endl;}
