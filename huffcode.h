#ifndef HUFFCODE_H
#define HUFFCODE_H

#include <string>
#include <map>

#include "binaryheap.h"

using std::string;
using std::map;

class HuffCode {
private:
	string data;
	string encoded;
	BinaryHeap* heap;
	map<char, int> freqTable;
	map<char, string> huffTable;

	void buildTable();
	void buildHeap();
	void getHuffCode(HuffNode*, string);
	void encode();

public:
	HuffCode(string);
	~HuffCode();
	string getData() {
		return data;
	};
	string getEncodedData() {
		return encoded;
	};
	string decodeData(string);

	void displayPostOrder();
	void displayHuffCodes();
};
#endif
