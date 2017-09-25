#ifndef PENTAGON_H
#define PENTAGON_H

#include <cstdlib>
#include "figure.hpp"

class Pentagon : public Figure{
    public:
        Pentagon();
    
        double Square() override;
        void Print() override;

        virtual ~Pentagon();

    private:
        double side;
        short int number;
};
#endif
