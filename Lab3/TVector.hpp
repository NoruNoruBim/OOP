#ifndef VECTOR_H
#define VECTOR_H

//#include "figure.hpp"
#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include "TVectorItem.hpp"
#include <memory>

class TVector {
    private:
        int size;
        std::shared_ptr<TVectorItem>* data;
    public:
        TVector(int size);

        bool Empty();
        int Size();

        void Print_node(int i);
        void Add(std::shared_ptr<Figure>& element);
        void Resize(int new_size);
        void Delete_node(int i);

        void Destroy();
        virtual ~TVector();
};

#endif
