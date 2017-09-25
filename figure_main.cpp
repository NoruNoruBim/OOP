#include <iostream>
#include <cstdlib>
#include "figure.hpp"
#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"

int main()
{
    short int number = 0;
    //double length = 0;

    std::cout << "Write number of sides and their length. This polygon must be regular." << std::endl;
    std::cout << "Number:" << std::endl;
    std::cin >> number;

    if ((number != 5 && number != 6 && number != 8) || number <= 0) {
        std::cout << "Incorrect input. Number must be equal 5, 6 or 8 and be bigger then zero. Length also must be bigger then zero.";
    } else {
        std::cout << "Length:" << std::endl;
        if (number == 5) {
            Figure* tmp = new Pentagon();
            tmp->Print();
            std::cout << "Square is:" << " " << tmp->Square() << std::endl;
            delete tmp;
        }
        if (number == 6) {
            Figure* tmp = new Hexagon();
            tmp->Print();
            std::cout << "Square is:" << " " << tmp->Square() << std::endl;
            delete tmp;
        }
        if (number == 8) {
            Figure* tmp = new Octagon();
            tmp->Print();
            std::cout << "Square is:" << " " << tmp->Square() << std::endl;
            delete tmp;
        }
    }
    
    return 0;
}
