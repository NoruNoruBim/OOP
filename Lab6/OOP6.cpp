#include <iostream>
#include <cstdlib>
#include <memory>

#include "figure.hpp"
#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include "TVector.hpp"
#include "TVectorItem.hpp"
#include "TIterator.hpp"
#include "TAllocationBlock.hpp"

int main()
{   
    TVector<Figure>* v = new TVector<Figure>();

    std::shared_ptr<Figure> tmp;

    short int code = -1, number = 0;
    int index = 0;

    std::cout << "Code 1 == add element. Code 2 == print element. Code 3 == delete element. Code 4 == print all array. Code 0 == break." << std::endl;
    
    while (code != 0) {
        std::cout << "Code:" << std::endl;
        std::cin >> code;

        if (code == 1) {
            std::cout << "Write number of sides:" << std::endl;
			std::cin >> number;
			std::cout << "Write length of side. This polygon must be regular." << std::endl;
			if (number == 5) {
				tmp = std::make_shared<Pentagon>(std::cin);
				v->Add(tmp);
				v->Resize((v->Size()) + 1);
			}
			if (number == 6) {
				tmp = std::make_shared<Hexagon>(std::cin);
				v->Add(tmp);
				v->Resize((v->Size()) + 1);
			}
			if (number == 8) {
				tmp = std::make_shared<Octagon>(std::cin);
				v->Add(tmp);
				v->Resize((v->Size()) + 1);
			}
			if (number != 5 && number != 6 && number != 8){
				std::cout << "Incorrect number. You can add only pentagon, hexagon and octagon." << std::endl;
			}
			
        }

        if (code == 2) {
            std::cout << "You can print elements. Write it's index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Size()) {
                v->Print_node(index);
            } else {std::cout << "Incorrect index." << std::endl;}
        }

        if (code == 3) {
            std::cout << "You can delete elements. Write index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Size()) {
                v->Delete_node(index);
                std::cout << "Element was deleted, size of array was reduced." << std::endl;
            }
            else {std::cout << "Incorrect index." << std::endl;}
        }
		if (code == 4 && !v->Empty()) {
			for (auto i : *v) i->Print();
		}
    }

    v->Destroy();

    return 0;
}
