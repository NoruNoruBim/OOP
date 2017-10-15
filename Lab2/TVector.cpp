#include "stdafx.h"
#include "TVector.hpp"


TVector::TVector(int size) {
    this->size = 0;
    this->data = (TVectorItem*)malloc((sizeof(TVectorItem)) * (size));
}

bool TVector::Empty() {
    return this->size == 0;
}

int TVector::Size() {
    return this->size;
}

void TVector::Print_node(int i) {
    //this->data[i].Print();
    std::cout << this->data[i];
}

void TVector::Add(Pentagon element) {
    TVectorItem* tmp = new TVectorItem(element);
    this->data[this->size] = *tmp;
    (this->size)++;
}

void TVector::Resize(int new_size) {//      control of size is not common
    this->data = (TVectorItem*)realloc(this->data, sizeof(TVectorItem) * new_size);
}

void TVector::Delete_node(int i) {//      shift and resize (and size--)
    for (int j = i; j != this->size - 1; j++) { this->data[j] = this->data[j + 1]; }
    this->Resize(--(this->size));
}

void TVector::Destroy() {
    if (size != 0) {
        this->size = 0;
        free(this->data);
    }
}

TVector::~TVector() { std::cout << "Vector was deleted" << std::endl; }
