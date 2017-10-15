#include "figure_pentagon.hpp"
#include <memory>
#include <iostream>
#include <stdlib.h>

int main()
{
    std::shared_ptr<Pentagon>* tmp = (std::shared_ptr<Pentagon>*)malloc(sizeof(std::shared_ptr<Pentagon>) * 10);
    //std::shared_ptr<Pentagon> tmp[10];

    //std::cout << "______0______" << std::endl;
    tmp[0] = std::make_shared<Pentagon>(std::cin);
	//std::cout << "______1______" << std::endl;
    tmp[0]->Print();
    //std::cout << "______2______" << std::endl;
    


    //int* tmp = (int*)malloc(sizeof(int) * 10);
    //std::cin >> tmp[0];

    //std::cout << tmp[0] << std::endl;


    system("pause");
    return 0;
}
