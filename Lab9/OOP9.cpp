#include <iostream>
#include <cstdlib>
#include <memory>

#include <future>
#include <functional>
#include <random>
#include <thread>

#include "figure.hpp"
#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include "TVector.hpp"
#include "TVector.h"
#include "TVectorItem.hpp"
#include "TVectorItem.h"
#include "TIterator.hpp"
//#include "TAllocationBlock.hpp"

int main(int argc, char** argv) {
	TVector<Figure>* vector_figure = new TVector<Figure>();
	typedef std::function<void (void)> command;
	TVector <command>* vector_cmd = new TVector<command>();
	
	command cmd_insert = [&]() {
		std::cout << "Command: Create pentagon, hexagon and octagon" << std::endl;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, 100);
		for (int i = 0; i < 3; i++) {
			
			int side = distribution(generator);
			std::shared_ptr<Figure> tmp;
			
			tmp = std::make_shared<Pentagon>(side);
			vector_figure->Add(tmp);
			vector_figure->Resize((vector_figure->Size()) + 1);
			
			tmp = std::make_shared<Hexagon>(side);
			vector_figure->Add(tmp);
			vector_figure->Resize((vector_figure->Size()) + 1);
			
			tmp = std::make_shared<Octagon>(side);
			vector_figure->Add(tmp);
			vector_figure->Resize((vector_figure->Size()) + 1);
		}
	};

	command cmd_print = [&]() {
		std::cout << "Command: Print vector" << std::endl;
		for (auto i : *vector_figure) i->Print();
		vector_figure->Print_node(vector_figure->Size() - 1);
	};
	
	command cmd_remove = [&]() {
		int size = 0;
		std::cout << "Write max square to delete." << std::endl;
		std::cin >> size;
		std::cout << "Command: Delete some nodes" << std::endl;
		vector_figure->Delete_by_size(size);
	};
	
	
	vector_cmd->Add_cmd(std::shared_ptr<command> (&cmd_insert, [](command*) {}));
	vector_cmd->Resize((vector_cmd->Size()) + 1);
		
	vector_cmd->Add_cmd(std::shared_ptr<command> (&cmd_print, [](command*) {})); // using custom deleter
	vector_cmd->Resize((vector_cmd->Size()) + 1);
		
	vector_cmd->Add_cmd(std::shared_ptr<command> (&cmd_remove, [](command*) {}));
	vector_cmd->Resize((vector_cmd->Size()) + 1);
		
	vector_cmd->Add_cmd(std::shared_ptr<command> (&cmd_print, [](command*) {}));
	vector_cmd->Resize((vector_cmd->Size()) + 1);
		
	
	for (int i = 0; i != vector_cmd->Size(); i++) {
		std::shared_ptr<command> cmd = vector_cmd->Get_node(i);
		std::future<void> ft = std::async(*cmd);
		ft.get();
		//std::thread(*cmd).detach();
	}

	return 0;
}