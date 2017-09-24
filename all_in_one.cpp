#include <iostream>
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES
using namespace std;


class Figure {
    public:
        virtual double Square() = 0;
        virtual void Print() = 0;

        virtual ~Figure() {};  
};


class Pentagon : public Figure{
    public:
        Pentagon(double side = 0) : side(side), number(5) {
            cin >> this->side;
            cout << "-Pentagon has created.-" << endl;
        }
        virtual ~Pentagon() {cout << "-Pentagon was deleted.-" << endl;}

        double Square() {
            double tmp = (5 * side * side) / (4 * tan((2 * M_PI) / 10));
            return tmp;
        }
        void Print() {
            cout << "Length of side is equal: " << side << ". Number of sides is " << number << "." << endl;
        }

    private:
        double side;
        short int number;
};


class Hexagon : public Figure{
    public:
        Hexagon(double side = 0) : side(side), number(6) {
            cin >> this->side;
            cout << "-Hexagon has created.-" << endl;
        }
        virtual ~Hexagon() {cout << "-Hexagon was deleted.-" << endl;}

        double Square() {
            double tmp = (6 * side * side) / (4 * tan((2 * M_PI) / 12));
            return tmp;
        }
        void Print() {
            cout << "Length of side is equal: " << side  << ". Number of sides is " << number << "." << endl;
        }

    private:
        double side;
        short int number;
};


class Octagon : public Figure{
    public:
        Octagon(double side = 0) : side(side), number(8) {
            cin >> this->side;
            cout << "-Octagon has created.-" << endl;
        }
        virtual ~Octagon() {cout << "-Octagon was deleted.-" << endl;}

        double Square() {
            double tmp = (8 * side * side) / (4 * tan((2 * M_PI) / 16));
            return tmp;
        }
        void Print() {
            cout << "Length of side is equal: " << side << ". Number of sides is " << number << "." << endl;
        }

    private:
        double side;
        short int number;
};


int main()
{
    short int number = 0;
    double length = 0;

    cout << "Write number of sides and their length. This polygon must be regular." << endl;
    cout << "Number:" << endl;
    cin >> number;
    cout << "Length:" << endl;

    if ((number != 5 && number != 6 && number != 8) || length < 0 || number <= 0) {
        cout << "Incorrect input. Number must be equal 5, 6 or 8 and be bigger then zero. Length also must be bigger then zero.";
    } else {
        if (number == 5) {
            Figure* tmp = new Pentagon();
            tmp->Print();
            cout << "Square is:" << " " << tmp->Square() << endl;
            delete tmp;
        }
        if (number == 6) {
            Figure* tmp = new Hexagon();
            tmp->Print();
            cout << "Square is:" << " " << tmp->Square() << endl;
            delete tmp;
        }
        if (number == 8) {
            Figure* tmp = new Octagon();
            tmp->Print();
            cout << "Square is:" << " " << tmp->Square() << endl;
            delete tmp;
        }
    }
    
    return 0;
}
