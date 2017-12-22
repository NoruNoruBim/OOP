#include <iostream>

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"

#include "TVector.hpp"
#include "TStack.h"

int main(void)
{
    TStack_1<TVector<Figure>, std::shared_ptr<Figure> > stack;
	
	Pentagon tmp1;
    Hexagon tmp2;
    Octagon tmp3;
	
    short int code = -1, number = 0;
    int index = 0;

    std::cout << "Code 1 == add element. Code 2 == print all array. Code 3 == delete element.  Code 0 == break." << std::endl;
    
    while (code != 0) {
        std::cout << "Code:" << std::endl;
        std::cin >> code;

        if (code == 1) {
            std::cout << "Write number of sides:" << std::endl;
			std::cin >> number;
			std::cout << "Write length of side. This polygon must be regular." << std::endl;
			if (number == 5) {
				std::cin >> tmp1;
				stack.push(std::make_shared<Pentagon>(tmp1));
                std::cout << "Item was added" << std::endl;
			}
			if (number == 6) {
				std::cin >> tmp2;
				stack.push(std::make_shared<Hexagon>(tmp2));
                std::cout << "Item was added" << std::endl;
			}
			if (number == 8) {
				std::cin >> tmp3;
				stack.push(std::make_shared<Octagon>(tmp3));
                std::cout << "Item was added" << std::endl;
			}
			if (number != 5 && number != 6 && number != 8){
				std::cout << "Incorrect number. You can add only pentagon, hexagon and octagon." << std::endl;
			}
			
        }
		if (code == 2) {
			stack.print();
		}
        if (code == 3) {
            std::cout << "You can delete elements. Write index." << std::endl;
            std::cin >> index;
            if (index >= 0) {
                //v->Delete_node(index);
                std::cout << "Element was deleted, size of container was reduced." << std::endl;
            }
            else {std::cout << "Incorrect index." << std::endl;}
        }
    }

    return 0;
}