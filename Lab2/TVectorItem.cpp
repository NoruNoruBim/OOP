#include "stdafx.h"
#include "TVectorItem.hpp"
#include <iostream>


TVectorItem::TVectorItem(Pentagon& pentagon) {
    this->pentagon = pentagon;
    std::cout << "Vector item: created" << std::endl;
}
TVectorItem::TVectorItem(const TVectorItem& orig) {
    this->pentagon = orig.pentagon;
    std::cout << "Vector item: copied" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const TVectorItem& obj) {
    os << "Length of side is equal: " << obj.pentagon << "." << std::endl;
    return os;
}

Pentagon TVectorItem::GetPentagon() const {
    return this->pentagon;
}

TVectorItem::~TVectorItem() {};
