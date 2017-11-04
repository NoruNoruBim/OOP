#include "TVectorItem.hpp"
#include <iostream>


template <class T> TVectorItem<T>::TVectorItem(std::shared_ptr<T>& figure) {
    this->figure = figure;
	this->next = nullptr;
    std::cout << "Vector item: created" << std::endl;
}

template <class T> std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<T>>& obj) {
    //os << "Length of side is equal: " << *(obj->figure) << "." << std::endl;
    obj->figure->Print();
	return os;
}

template <class T> std::shared_ptr<T> TVectorItem<T>::GetFigure() const {
    return this->figure;
}

template <class T> std::shared_ptr<TVectorItem<T>> TVectorItem<T>::GetNext() const {
	//std::cout << this->next;
	return this->next;
}

template <class T> void TVectorItem<T>::SetNext(std::shared_ptr<TVectorItem<T>> next) {
	this->next = next;
}

template <class T> void * TVectorItem<T>::operator new (size_t size) {
	std::cout << "Allocated :" << size << "bytes" << std::endl;
	return malloc(size);
}
template <class T> void TVectorItem<T>::operator delete(void *p) {
	std::cout << "Deleted" << std::endl;
	free(p);
}



template <class T> TVectorItem<T>::~TVectorItem() {};

template class TVectorItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<Figure>>& obj);
