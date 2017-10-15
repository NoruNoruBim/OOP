#include "TVectorItem.hpp"
#include <iostream>


TVectorItem::TVectorItem(std::shared_ptr<Figure>& figure) {
    this->figure = figure;
    std::cout << "Vector item: created" << std::endl;
}

/*TVectorItem::TVectorItem(const TVectorItem& orig) {
this->pentagon = orig.pentagon;
std::cout << "Vector item: copied" << std::endl;
}*/

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem>& obj) {
    //os << "Length of side is equal: " << *(obj->figure) << "." << std::endl;
    obj->figure->Print();
	return os;
}

std::shared_ptr<Figure> TVectorItem::GetFigure() const {
    return this->figure;
}

TVectorItem::~TVectorItem() {};
