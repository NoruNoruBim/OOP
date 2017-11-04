#ifndef ITEM_H
#define ITEM_H

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include <memory>

template <class T> class TVectorItem {
    private:
        std::shared_ptr<T> figure;
		std::shared_ptr<TVectorItem<T>> next;
    public:
        TVectorItem(std::shared_ptr<T>& figure);
        template <class A> friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<A>>& obj);//shared?

        std::shared_ptr<T> GetFigure() const;
        std::shared_ptr<TVectorItem<T>> GetNext() const;
		void SetNext(std::shared_ptr<TVectorItem<T>> next);

		void * operator new (size_t size);
		void operator delete(void *p);

        virtual ~TVectorItem();
};

#endif
