#include "TVectorItem.hpp"
#include <iostream>


template <class T> TVectorItem<T>::TVectorItem(std::shared_ptr<T>& figure, std::recursive_mutex* parent) {
    this->v_mutex = parent;
	this->figure = figure;
	this->next = nullptr;
    std::cout << "Vector item: created" << std::endl;
}

/*template <class T> TVectorItem<T>::TVectorItem(T* item,std::recursive_mutex* parent) {
	this->v_mutex = parent;
	this->figure = figure;
	this->next = nullptr;
    std::cout << "Vector item: created" << std::endl;
}
template <class T> TVectorItem<T>::TVectorItem(std::shared_ptr<T>& item,std::recursive_mutex *parent) {
	this->v_mutex = parent;
	this->figure = figure;
	this->next = nullptr;
    std::cout << "Vector item: created" << std::endl;
}*/


//template <class T> TAllocationBlock TVectorItem<T>::vectoritem_allocator(sizeof(TVectorItem<T>), 10000);//initialization of var class TAllocationItem

template <class T> std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<T>>& obj) {
    obj->figure->Print();
	return os;
}

template <class T> std::shared_ptr<T> TVectorItem<T>::GetFigure() const {
	std::unique_lock<std::recursive_mutex> lock(*v_mutex);
    return this->figure;
}

template <class T> std::shared_ptr<TVectorItem<T>> TVectorItem<T>::GetNext() const {
	std::lock_guard<std::recursive_mutex> lock(*v_mutex);
	return this->next;
}

template <class T> void TVectorItem<T>::SetNext(std::shared_ptr<TVectorItem<T>> next) {
	std::unique_lock<std::recursive_mutex> lock(*v_mutex);
	this->next = next;
}

/*template <class T> void* TVectorItem<T>::operator new (size_t size) {
	return vectoritem_allocator.Allocate();
}
template <class T> void TVectorItem<T>::operator delete(void *p) {//	?? we managed but dont free blocks like original function free
	vectoritem_allocator.Deallocate(p);
}*/



template <class T> TVectorItem<T>::~TVectorItem() {};

template class TVectorItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<Figure>>& obj);

/*
#include "Triangle.h"
#include <functional>
template class TStackItem<Triangle>;
template class TStackItem<std::function<void(void)>>;
template std::ostream& operator<<(std::ostream& os, const TStackItem<Triangle>& obj);
*/

