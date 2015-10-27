#ifndef HUFFMAN_H
#define HUFFMAN_H

using namespace std;
#include <iostream>

class HuffmanTree
{
public:
	struct Node
		{
			char value;
			int count;
			Node *left;
			Node *right;
		};

		Node *root;

	HuffmanTree() // constructor
	{
		root = NULL;
	}

	~HuffmanTree()
	{
		//destroySubTree(root);
	}

	void reader();
	void huffman();
	void postOrder();
	void encode();
};

#endif
