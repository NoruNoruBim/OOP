#include "TVector.hpp"
#include <iostream>

template <class T> TVector<T>::TVector(int size) {
    this->size = 0;
    this->data = (std::shared_ptr<TVectorItem<T>>*)malloc(sizeof(std::shared_ptr<TVectorItem<T>>) * size);
}

template <class T> bool TVector<T>::Empty() {
    return this->size == 0;
}

template <class T> int TVector<T>::Size() {
    return this->size;
}

template <class T> void TVector<T>::Print_node(int i) {
	std::cout << this->data[i];
	std::cout << this->data[i]->GetNext();
}

template <class T> void TVector<T>::Add(std::shared_ptr<T>& element) {
    this->data[size] = std::make_shared<TVectorItem<T>>(element);
	(this->size)++;
}

template <class T> void TVector<T>::Resize(int new_size) {//      control of size is not common
    this->data = (std::shared_ptr<TVectorItem<T>>*)realloc(this->data, sizeof(Pentagon) * new_size);
	if (size >= 2) this->data[size - 2]->SetNext(this->data[size - 1]);
}

template <class T> void TVector<T>::Delete_node(int i) {//      shift and resize (and size--)
    for (int j = i; j != this->size - 1; j++) { this->data[j] = this->data[j + 1]; }
    this->Resize(--(this->size));
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::begin() {
	return this->data[0];
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::end() {
	return this->data[this->size];
}

template <class T> void TVector<T>::Destroy() {
    if (size != 0) {
        this->size = 0;
        free(this->data);
    }
	std::cout << "Vector was deleted." << std::endl;
}

template <class T> TVector<T>::~TVector() { std::cout << "Vector was deleted" << std::endl; }

template class TVector<Figure>;
