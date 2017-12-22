#ifndef ITEM_H
#define ITEM_H

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
//#include "TAllocationBlock.hpp"

#include <memory>
#include <mutex>
#include <thread>

template <class T> class TVectorItem {
    private:
        std::shared_ptr<T> figure;
		std::shared_ptr<TVectorItem<T>> next;
		//static TAllocationBlock vectoritem_allocator;// aka global var
		
		std::recursive_mutex* v_mutex;
    public:
        TVectorItem(std::shared_ptr<T>& figure, std::recursive_mutex* parent);
		
		//TVectorItem(T *item, std::recursive_mutex *parent);
		//TVectorItem(std::shared_ptr<T>& item, std::recursive_mutex* parent);
		
        template <class A> friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem<A>>& obj);//shared?

        std::shared_ptr<T> GetFigure() const;
        std::shared_ptr<TVectorItem<T>> GetNext() const;
		void SetNext(std::shared_ptr<TVectorItem<T>> next);

		//void * operator new (size_t size);
		//void operator delete(void *p);

        virtual ~TVectorItem();
};

#endif

