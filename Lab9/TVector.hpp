#ifndef VECTOR_H
#define VECTOR_H

#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include "TVectorItem.hpp"
#include "TIterator.hpp"

#include <memory>
#include <future>
#include <mutex>
#include <thread>


template <class T> class TVector {
    private:
        int32_t size;
        std::shared_ptr<TVectorItem<T>>* data;
		
		std::recursive_mutex v_mutex;
    public:
        TVector();

        bool Empty();
        int32_t Size();

        void Print_node(int32_t i);
		std::shared_ptr<T> Get_node(int index);
		
        void Add(std::shared_ptr<T>& element);
		void Add_cmd(std::shared_ptr<T> element);
	
        void Resize(int32_t new_size);
		
        void Delete_node(int i);
		void Delete_by_size(int size);
		
		TIterator<TVectorItem<T>,T> begin() const;
		TIterator<TVectorItem<T>,T> end() const;

		std::shared_ptr<T> operator[] (size_t i);
		
        void Destroy();
        virtual ~TVector();
};

#endif
