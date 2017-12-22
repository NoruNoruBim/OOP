#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Hexagon : public Figure {
    public:
        Hexagon ();
		Hexagon(int& side);
        Hexagon(std::istream &is);
        Hexagon(const Hexagon& orig);

        double Square() override;
        void Print() override;

		friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
        friend std::istream& operator>>(std::istream& is, Hexagon& obj);
        Hexagon& operator=(const Hexagon& right);
		
        virtual ~Hexagon();

    private:
        double side;
};
#endif
