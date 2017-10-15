#ifndef PENTAGON_H
#define PENTAGON_H

#include <cstdlib>
#include <iostream>

class Pentagon {
    public:
        Pentagon();
        Pentagon(std::istream &is);
        Pentagon(const Pentagon& orig);

        double Square();
        void Print();

        friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
        friend std::istream& operator>>(std::istream& is, Pentagon& obj);
        Pentagon& operator=(const Pentagon& right);

        virtual ~Pentagon();

    private:
        double side;
};
#endif
