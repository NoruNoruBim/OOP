#ifndef ITEM_H
#define ITEM_H

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include <memory>

template <class T> class TVectorItem {
    private:
        std::shared_ptr<T> figure;
    public:
        TVectorItem(std::shared_ptr<T>& figure);
        //TVectorItem(const std::shared_ptr<Pentagon>& orig);
        template <class A> friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<A>>& obj);//shared?

        std::shared_ptr<T> GetFigure() const;


        virtual ~TVectorItem();
};

#endif
