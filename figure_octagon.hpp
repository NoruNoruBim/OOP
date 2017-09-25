#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include "figure.hpp"

class Octagon : public Figure{
    public:
        Octagon();

        double Square() override;
        void Print() override;
        
        virtual ~Octagon();

    private:
        double side;
        short int number;
};
#endif
