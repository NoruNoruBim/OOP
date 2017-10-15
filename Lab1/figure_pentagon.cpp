#include "figure_pentagon.hpp"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Pentagon::Pentagon() {
    this->side = 0;
}

Pentagon::Pentagon(std::istream &is) {
    std::cout << "Write length of side:" << std::endl;
	is >> this->side;;
    if (side < 0) {
        std::cout << "Input error. ";
    } else {std::cout << "-Pentagon was created.-" << std::endl;}
}

Pentagon::Pentagon(const Pentagon& orig) {
    std::cout << "Pentagon copy created" << std::endl;
    this->side = orig.side;
}

double Pentagon::Square() {
    double tmp = (5 * side * side) / (4 * tan((2 * pi) / 10));
    return side < 0 ? 404 : tmp;
}
void Pentagon::Print() {
    if (side >= 0) std::cout << "Length of side is equal: " << side << ". Square is " << this->Square() << "." << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
    os << obj.side/*<< std::endl*/;
    return os;
}
std::istream& operator>>(std::istream& is, Pentagon& obj) {
    is >> obj.side;
    if (obj.side < 0) {
        std::cout << "Input error. ";
    }
    else { std::cout << "-Pentagon was created.-" << std::endl; }
    return is;
}

Pentagon& Pentagon::operator=(const Pentagon& right) {
    if (this == &right) return *this;
    //std::cout << "Pentagon copied" << std::endl;
    side = right.side;
    return *this;
}

Pentagon::~Pentagon() {std::cout << "-Pentagon was deleted.-" << std::endl;}
