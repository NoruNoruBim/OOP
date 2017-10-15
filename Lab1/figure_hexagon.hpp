#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Hexagon : public Figure{
    public:
        Hexagon ();
        Hexagon(std::istream &is);
        Hexagon(const Hexagon& orig);

        double Square() override;
        void Print() override;

        virtual ~Hexagon();

    private:
        double side;
        short int number;
};
#endif
