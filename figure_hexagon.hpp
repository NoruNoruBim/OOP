#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include "figure.hpp"

class Hexagon : public Figure{
    public:
        Hexagon ();

        double Square() override;
        void Print() override;

        virtual ~Hexagon();

    private:
        double side;
        short int number;
};
#endif
