// Project goals:
// 1. read in the file to be encoded
// 	  construct the huffman tree
// 2. display the huffman code to std output ( a(4):1001 )
// 3. output the post-order traversal of the tree (a1e2@5@6; using @ for interior nodes)
// 4. encode the loaded file and save it to a .hzip file
// 	  use 0's to pad the rest of the document (see example)
#include <iostream>
#include <fstream>
#include <string>

#include "huffnode.h"
using namespace std;

//initializing
HuffNode::HuffNode() {
	value = ' ';
	freq = 0;
	left = NULL;
	right = NULL;
}

HuffNode::HuffNode(char v, int i) {
	value = v;
	freq = i;
	left = NULL;
	right = NULL;
}

HuffNode::HuffNode(HuffNode* left, HuffNode* right) {
	this->left = left;
	this->right = right;
	freq = left->getFreq() + right->getFreq(); // an interior node takes the freq from both children as its own freq
	value = NULL;
}

HuffNode::~HuffNode() { // destructor
	if (left != NULL) {
		delete left;
	}
	if (right != NULL) {
		delete right;
	}
}

HuffNode::HuffNode(const HuffNode& rhs) {
	if(rhs.left != NULL) {
		left = new HuffNode();
		*left = *(rhs.left);
	}
	if(rhs.right != NULL) {
		right = new HuffNode();
		*right = *(rhs.right);
	}
	code = rhs.code;
	value = rhs.value;
	freq = rhs.freq;
}

ostream& operator << (ostream& os, const HuffNode& rhs) {
	os << "\'" << rhs.value << " " << rhs.freq << "\'";
	return os;
}

HuffNode& HuffNode::operator=(const HuffNode& rhs) {
	if (!(this == &rhs)) { // create a copy
		code = rhs.code;
		value = rhs.value;
		freq = rhs.freq;
		if(!(left == NULL)) {
			delete left;
		}
		if(!(right == NULL)) {
			delete right;
		}

		if (rhs.left != NULL) {
			left = new HuffNode();
			*left = *(rhs.left);

			if (rhs.right != NULL) {
				right = new HuffNode();
				*right = *(rhs.right);
			}
		}
		else {
			left = NULL;
			right = NULL;
		}
	}
	return *this;
}