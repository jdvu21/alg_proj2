#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <string>
using std::ostream;

class HuffNode
{
private:
		char value;
		int freq;
		std::string code;
		HuffNode *left;
		HuffNode *right;
public:
	HuffNode(); // constructor
	HuffNode(char, int);
	HuffNode(HuffNode*, HuffNode*);
	HuffNode(const HuffNode&);
	~HuffNode();

// ===== FUNCTIONS ======

	int getFreq() {
		return freq;
	}

	char getValue() {
		return value;
	}

	std::string getCode() {
		return code;
	}

	HuffNode* getLeft() {
		return left;
	}

	HuffNode* getRight() {
		return right;
	}

	void setHuffCode(std::string s) {
		code = s;
	};

	friend ostream& operator<<(ostream&, const HuffNode&);

	HuffNode& operator = (const HuffNode&);
};

#endif
