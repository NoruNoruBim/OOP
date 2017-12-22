#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TStack.hpp"

class TAllocationBlock {
	public:
		TAllocationBlock(int32_t size, int32_t count);
		void *Allocate();
		void Deallocate(void *pointer);
		bool Empty();

		int32_t Size();
		
		virtual ~TAllocationBlock();
	private:
	unsigned char *_used_blocks;
    TStack<void *>_free_blocks;
};

#endif
