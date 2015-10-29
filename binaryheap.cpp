#include "binaryheap.h"
#include <iostream>
using namespace std;

BinaryHeap::BinaryHeap(int size) {
	capacity = size;
	heapSize = 0;
	storage = new HuffNode*[capacity];
	for (int i = 0; i < capacity; i++) {
		storage[i] = NULL;
	}
}

BinaryHeap::~BinaryHeap() {
	if(storage != NULL) {
		for(int i = 0; i < capacity; ++i) {
			if (storage[i] != NULL) {
				delete storage[i];
				heapSize--;
			}
		}
		delete[] storage;
	}
}

void BinaryHeap::insert(HuffNode* rhs) {
	if(heapSize == capacity) {
		return; // no room, do not procede
	}

	heapSize++;
	storage[heapSize - 1] = rhs;
	percUp(heapSize - 1);
}

void BinaryHeap::percUp(int current) {
	int parentIndex;
	HuffNode* temp;

	if (current != 0) {
		parentIndex = (current - 1) / 2;
		if (storage[parentIndex]->getFreq() > storage[current]->getFreq()) {
			temp = storage[parentIndex];
			storage[parentIndex] = storage[current];
			storage[current] = temp;
			percUp(parentIndex);
		}
	}
}

int BinaryHeap::numChildren(int index) {
	int children = 0;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if(left >= heapSize) {
		return 0;
	}
	if (storage[left] != NULL) {
		children++;
	}
	if (storage[right] != NULL) {
		children++;
	}
	return children;
}

void BinaryHeap::percDown(int current) {
	int children = 0;
	if (children = numChildren(current)) {
		HuffNode* temp;
		int left = 2 * current + 1;
		int right = 2* current + 2;
		switch(children) {
			case 1:
				if (storage[current]->getFreq() > storage[left]->getFreq()) {
					temp = storage[current];
					storage[current] = storage[left];
					storage[left] = temp;
					percDown(left);
				}
				break;
			case 2: // of 2 children, which is smaller, perc towards that child
				if ((storage[current]->getFreq() > storage[left]->getFreq()) ||
					(storage[current]->getFreq() > storage[right]->getFreq())) {
					//left child is smaller
					if((storage[left]->getFreq() < storage[right]->getFreq())) {
						temp = storage[current];
						storage[current] = storage[left];
						storage[left] = temp;
						percDown(left);
					}
					else { //right child is smaller
						temp = storage[current];
						storage[current] = storage[right];
						storage[right] = temp;
						percDown(right);
					}
				}
				break;
				default:
					std::cout << "error determining smaller child" << endl;
					break;
		}
	}
	return;
}

HuffNode* BinaryHeap::removeMin() {
	HuffNode* value = new HuffNode();
	*value = *storage[0];

	HuffNode* temp = storage[0];
	storage[0] = storage[heapSize - 1];
	storage[heapSize - 1] = temp;
	delete storage[heapSize - 1];
	storage [heapSize - 1] = NULL;
	heapSize--;
	percDown(0);
	return value;
}

bool BinaryHeap::isEmpty() {
	return (heapSize == 0);
}

void BinaryHeap::postOrderTraversal() {
	if (isEmpty()) {
		return;
	}
	postOrder(0);
}

void BinaryHeap::postOrder(int current) {
	// left
	if(((2 * current + 1) < capacity) && (storage[2*current+1] != NULL)) {
		postOrder(2 * current + 1);
	}
	// right
	if(((2 * current + 2) < capacity) && (storage[2*current+2] != NULL)) {
		postOrder(2 * current + 2);
	}
	// current
	std::cout << *storage[current] << " ";
}

void BinaryHeap::linearDisplay() {
	for (int i = 0; i < heapSize; ++i) {
		std::cout << *storage[i] << " ";
	}
	std::cout << endl;
}
