#ifndef VECTOR_H
#define VECTOR_H

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include "TVectorItem.hpp"
#include "TIterator.hpp"
#include <memory>


template <class T> class TVector {
    private:
        int size;
        std::shared_ptr<TVectorItem<T>>* data;
    public:
        TVector(int size);

        bool Empty();
        int Size();

        void Print_node(int i);
        void Add(std::shared_ptr<T>& element);
        void Resize(int new_size);
        void Delete_node(int i);

		TIterator<TVectorItem<T>,T> begin();
		TIterator<TVectorItem<T>,T> end();
		
        void Destroy();
        virtual ~TVector();
};

#endif
