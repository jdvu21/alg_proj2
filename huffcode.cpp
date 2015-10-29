#include "huffcode.h"
#include <iostream>
#include <utility>
#include <map>

using namespace std;

HuffCode::HuffCode(string source) {
	data = source;
	encoded = "";
	heap = new BinaryHeap(data.length()); // we must assume worst case: data is all unique characters
	buildTable();
	buildHeap();
}

HuffCode::~HuffCode() { //destructor
	if (heap != NULL) {
		delete heap;
	}
}

void HuffCode::buildTable() {
	for (size_t i = 0; i < data.length(); ++i) { // size_t is an unsigned integral type, found in sizeof operator
		char c = data.at(i);
		if (freqTable.find(data.at(i)) == freqTable.end()) {
			freqTable.insert(pair<char, int>(c, 1));
		}
		else {
			freqTable[c]++;
		}
	}
}

void HuffCode::buildHeap() {
	// to fill the heap
	for (map<char, int>::iterator it = freqTable.begin();
		it != freqTable.end(); ++it) {
		heap->insert(new HuffNode(it->first, it->second));
	}
	while (!heap->isEmpty()) { // removing two each loop until only one remains
		if (heap->getHeapSize() == 1) {
			break;
		}
		HuffNode* left = heap->removeMin();
		HuffNode* right = heap->removeMin();
		heap->insert(new HuffNode(left,right));
	}
	string code = "";
	getHuffCode(heap->getRoot(),code);
	encode();
}

void HuffCode::getHuffCode(HuffNode* root, string code) {
	if (root->getLeft() == NULL) {
		root->setHuffCode(code);
		huffTable.insert(pair<char, string>(root->getValue(), code));
		return;
	}
	else {
		getHuffCode(root->getLeft(), code.append("0"));
		getHuffCode(root->getRight(), code.append("1"));
		//getHuffCode(root->getLeft(), code+"0");
		//getHuffCode(root->getRight(), code+"1");
	}
}

void HuffCode::encode() {
	for (size_t i = 0; i < data.length(); ++i) {
		encoded.append(huffTable[data.at(i)]);
		//encoded.append(" "); // no spaces in our encoded data for maximum space reduction
	}
}

void HuffCode::displayHuffCodes() {
	for (map <char, string>::iterator it = huffTable.begin();
		it != huffTable.end(); ++it) {
		std::cout << it->first << "(" << it->second.size() << ")" << it->second << endl;
	}
}

void HuffCode::displayPostOrder() {
	heap->postOrderTraversal();
	cout << endl;
}
