#ifndef TStack_1_H
#define TStack_1_H

#include "figure.hpp"
#include "TStack_1.hpp"

#include <memory>
#include <iostream>

template <typename Q, typename O> class TStack_1 {
	private:
		class Node {
			public:
				Q data;
				std::shared_ptr<Node> next;
				Node();
				Node(const O&);
				int itemsInNode;
			};

		std::shared_ptr<Node> head;
		int count;
	public:
		TStack_1();

		void push(const O&);
		void print(); 
		//void removeByType(const int&);
		void removeLesser(const double&);
};

#endif