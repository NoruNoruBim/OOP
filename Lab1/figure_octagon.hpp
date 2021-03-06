#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Octagon : public Figure{
    public:
        Octagon();
        Octagon(std::istream &is);
        Octagon(const Octagon& orig);

        double Square() override;
        void Print() override;
        
        virtual ~Octagon();

    private:
        double side;
        short int number;
};
#endif
