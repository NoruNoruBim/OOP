#include "TVector.hpp"
#include <iostream>

TVector::TVector(int size) {
    this->size = 0;
    this->data = (std::shared_ptr<TVectorItem>*)malloc(sizeof(std::shared_ptr<TVectorItem>) * size);
}

bool TVector::Empty() {
    return this->size == 0;
}

int TVector::Size() {
    return this->size;
}

void TVector::Print_node(int i) {
    std::cout << this->data[i];
}

void TVector::Add(std::shared_ptr<Figure>& element) {
    std::shared_ptr<TVectorItem> t = std::make_shared<TVectorItem>(element);
    this->data[size] = t;
    (this->size)++;
}

void TVector::Resize(int new_size) {//      control of size is not common
    this->data = (std::shared_ptr<TVectorItem>*)realloc(this->data, sizeof(Pentagon) * new_size);
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
	std::cout << "Vector was deleted." << std::endl;
}

TVector::~TVector() { std::cout << "Vector was deleted" << std::endl; }
