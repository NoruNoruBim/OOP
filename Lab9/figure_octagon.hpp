#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Octagon : public Figure {
    public:
        Octagon();
		Octagon(int& side);
        Octagon(std::istream &is);
        Octagon(const Octagon& orig);

        double Square() override;
        void Print() override;
        
		friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
        friend std::istream& operator>>(std::istream& is, Octagon& obj);
        Octagon& operator=(const Octagon& right);
		
        virtual ~Octagon();

    private:
        double side;
};
#endif
