#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "figure_pentagon.hpp"
#include "TVector.hpp"
#include "TVectorItem.hpp"

using namespace std;
typedef unsigned long long Type;


int main()
{   
    TVector* v = new TVector(1);
    Pentagon tmp;

    short int code = 0;
    int index = 0;

    std::cout << "Code 1 means add element. Code 2 means print element. Code 3 means delete element. Code 4 means break." << std::endl;
    
    while (code != 4) {
        std::cout << "Code:" << std::endl;
        std::cin >> code;

        if (code == 1) {
            std::cout << "Write length of side. This pentagon must be regular." << std::endl;
            std::cout << "Length:" << std::endl;

            cin >> tmp;

            v->Add(tmp);
            v->Resize((v->Size()) + 1);
        }

        if (code == 2) {
            std::cout << "You can print elements. Write it's index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Size()) {
                v->Print_node(index);
            } else {cout << "Incorrect index." << endl;}
        }

        if (code == 3) {
            std::cout << "You can delete elements. Write index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Size()) {
                v->Delete_node(index);
                cout << "Element was deleted, size of array was reduced." << endl;
            }
            else {cout << "Incorrect index." << endl;}
        }
    }

    v->Destroy();

    return 0;
}
