#include "TVectorItem.hpp"
#include <iostream>


template <class T> TVectorItem<T>::TVectorItem(std::shared_ptr<T>& figure) {
    this->figure = figure;
    std::cout << "Vector item: created" << std::endl;
}

/*TVectorItem::TVectorItem(const TVectorItem& orig) {
this->pentagon = orig.pentagon;
std::cout << "Vector item: copied" << std::endl;
}*/

template <class T> std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<T>>& obj) {
    //os << "Length of side is equal: " << *(obj->figure) << "." << std::endl;
    obj->figure->Print();
	return os;
}

template <class T> std::shared_ptr<T> TVectorItem<T>::GetFigure() const {
    return this->figure;
}

template <class T> TVectorItem<T>::~TVectorItem() {};

template class TVectorItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<Figure>>& obj);
