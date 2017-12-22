#include "TVector.hpp"
#include <iostream>

template <class T> TVector<T>::TVector() {
    this->size = 0;
    this->data = (std::shared_ptr<TVectorItem<T>>*)malloc(sizeof(std::shared_ptr<TVectorItem<T>>) * 1);
    
	this->data = (std::shared_ptr<TVectorItem<T>>*)malloc(sizeof(std::shared_ptr<TVectorItem<T>>) * 1);
}

template <class T> bool TVector<T>::Empty() {
    return this->size == 0;
}

template <class T> int32_t TVector<T>::Size() {
    return this->size;
}

template <class T> void TVector<T>::Print_node(int32_t i) {
	std::cout << this->data[i];
}

template <class T> void TVector<T>::Add(std::shared_ptr<T>& element) {
    this->data[size] = std::make_shared<TVectorItem<T>>(element);
	(this->size)++;
}

template <class T> void TVector<T>::Resize(int32_t new_size) {//      control of size is not common
    this->data = (std::shared_ptr<TVectorItem<T>>*)realloc(this->data, sizeof(TVectorItem<T>) * new_size);
	if (size >= 2) this->data[size - 2]->SetNext(this->data[size - 1]);
}

template <class T> void TVector<T>::Delete_node(int32_t i) {//      shift and resize (and size--)
    for (int32_t j = i; j != this->size - 1; j++) { this->data[j] = this->data[j + 1]; }
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

template <class T> void TVector<T>::Sort() {
	if (this->size > 0) {
		for (int32_t i = 0; i != this->size - 1; i++) {
			if (this->data[i]->GetFigure()->Square() > this->data[i + 1]->GetFigure()->Square()) swap(this->data[i], this->data[i + 1]);
		}
        this->size--;
		Sort();
	} else {
		for (int32_t i = 0; this->data[i] != nullptr; i++) {this->data[i]->SetNext(this->data[i + 1]); this->size++;}// normalize order of elements
	}
}


template<class T > std::future<void> TVector<T>::sort_in_background() {
	std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TVector<T>::Sort_parallel), this));
	
	std::future<void> res(task.get_future());
	
	std::thread th(std::move(task));
	std::cout << std::this_thread::get_id() << std::endl;
	th.detach();
	
	return res;
}

template <class T> void TVector<T>::Sort_parallel() {
	if (this->size > 0) {
		for (int32_t i = 0; i != this->size - 1; i++) {
			if (this->data[i]->GetFigure()->Square() > this->data[i + 1]->GetFigure()->Square()) swap(this->data[i], this->data[i + 1]);
		}
        this->size--;
		std::future<void> result = this->sort_in_background();
		result.get();
		
	} else {
		for (int32_t i = 0; this->data[i] != nullptr; i++) {this->data[i]->SetNext(this->data[i + 1]); this->size++;}// normalize order of elements
	}
}


template <class T> void TVector<T>::Sort_part() {
	for (int32_t i = this->Size() - 1; i != 0; i--) {
			if (this->data[i]->GetFigure()->Square() < this->data[i - 1]->GetFigure()->Square()) swap(this->data[i], this->data[i - 1]);
	}
}


template <class T> TVector<T>::~TVector() { /*std::cout << "Vector was deleted." << std::endl;*/ }

template class TVector<Figure>;
