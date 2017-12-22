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
        int32_t size;
        std::shared_ptr<TVectorItem<T>>* data;
    public:
        TVector();

        bool Empty();
        int32_t Size();

        void Print_node(int32_t i);
        void Add(const std::shared_ptr<T>& element);
        void Resize(int32_t new_size);
        void Delete_node(int32_t i);

		TIterator<TVectorItem<T>,T> begin();
		TIterator<TVectorItem<T>,T> end();
		
        void Destroy();
        virtual ~TVector();
};

#endif
