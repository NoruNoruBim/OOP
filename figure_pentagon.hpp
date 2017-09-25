#ifndef PENTAGON_H
#define PENTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Pentagon : public Figure{
    public:
        Pentagon();
        Pentagon(std::istream &is);
        Pentagon(const Pentagon& orig);

        double Square() override;
        void Print() override;

        virtual ~Pentagon();

    private:
        double side;
        short int number;
};
#endif
