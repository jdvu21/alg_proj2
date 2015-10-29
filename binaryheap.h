#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "huffnode.h"

class BinaryHeap {
private:
	HuffNode** storage;
	int heapSize;
	int capacity;

	void percUp(int);
	void percDown(int);
	int numChildren(int);

	void postOrder(int);

public:
	BinaryHeap(int);
	~BinaryHeap();
	void insert(HuffNode*);
	HuffNode* removeMin();
	HuffNode peekMin(); // for debug

	bool isEmpty();
	int getHeapSize() {
		return heapSize;
	}
	HuffNode* getRoot() { // also for debug
		return storage[0];
	}

	void postOrderTraversal();
	void linearDisplay();
	void emptyHeap();
};
#endif
