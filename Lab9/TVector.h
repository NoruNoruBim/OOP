#include "TVector.hpp"

#include <iostream>
#include <exception>

template <class T> TVector<T>::TVector() {
    this->size = 0;
    this->data = (std::shared_ptr<TVectorItem<T>>*)malloc(sizeof(std::shared_ptr<TVectorItem<T>>) * 1);    
}

template <class T> bool TVector<T>::Empty() {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    return this->size == 0;
}

template <class T> int32_t TVector<T>::Size() {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    return this->size;
}

template <class T> void TVector<T>::Print_node(int32_t i) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
	std::cout << this->data[i];
}

template <class T> std::shared_ptr<T> TVector<T>::Get_node(int i) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
	return this->data[i]->GetFigure();
}

template <class T> void TVector<T>::Add(std::shared_ptr<T>& element) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    this->data[size] = std::make_shared<TVectorItem<T>>(element, &v_mutex);
	(this->size)++;
}

template <class T> void TVector<T>::Add_cmd(std::shared_ptr<T> element) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    this->data[size] = std::make_shared<TVectorItem<T>>(element, &v_mutex);
	(this->size)++;
}

template <class T> void TVector<T>::Resize(int32_t new_size) {//      control of size is not common
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    this->data = (std::shared_ptr<TVectorItem<T>>*)realloc(this->data, sizeof(TVectorItem<T>) * new_size);
	if (size >= 2) this->data[size - 2]->SetNext(this->data[size - 1]);
}

template <class T> void TVector<T>::Delete_node(int i) {//      shift and resize (and size--)
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    for (int j = i; j != this->size - 1; j++) { this->data[j] = this->data[j + 1]; }
    this->Resize(--(this->size));
	for (int i = 0; i != this->Size(); i++) this->data[i]->SetNext(this->data[i + 1]);
}

template <class T> void TVector<T>::Delete_by_size(int size) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
	for (int index = 0; index != this->Size();) {
		if (this->data[index]->GetFigure()->Square() < size) {
			Delete_node(index);
		} else {
			index++;
		}
	}
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::begin() const {
	return this->data[0];
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::end() const {
	return this->data[this->size];
}

template <class T> void TVector<T>::Destroy() {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
    if (size != 0) {
        this->size = 0;
        free(this->data);
    }
	std::cout << "Vector was deleted." << std::endl;
}

template <class T> std::shared_ptr<T> TVector<T>::operator[](size_t i) {
	std::lock_guard<std::recursive_mutex> lock(v_mutex);
	if (i > this->Size() - 1) throw std::invalid_argument("index greater then stack size");
	size_t j = 0;
	for (std::shared_ptr<T> a : * this) {
		if (j == i) return a;
		j++;
	}
	return std::shared_ptr<T>(nullptr);
}



template <class T> TVector<T>::~TVector() { /*std::cout << "Vector was deleted." << std::endl;*/ }

template class TVector<Figure>;
