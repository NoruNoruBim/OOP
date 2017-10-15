#ifndef VECTOR_H
#define VECTOR_H

#include "figure_pentagon.hpp"
#include "TVectorItem.hpp"

class TVector {
    private:
        int size;
        TVectorItem* data;
    public:
        TVector(int size);

        bool Empty();
        int Size();

        void Print_node(int i);
        void Add(Pentagon element);
        void Resize(int new_size);
        void Delete_node(int i);

        void Destroy();
        virtual ~TVector();
};

#endif
