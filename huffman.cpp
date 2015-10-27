// Project goals:
// 1. read in the file to be encoded
// 	  construct the huffman tree
// 2. display the huffman code to std output ( a(4):1001 )
// 3. output the post-order traversal of the tree (a1e2@5@6; using @ for interior nodes)
// 4. encode the loaded file and save it to a .hzip file
// 	  use 0's to pad the rest of the document (see example)

#include "huffman.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void HuffmanTree::reader(string fpath) {
    string path = fpath;
    char ch;
	ifstream inFile;

	inFile.open(path.c_str());
	if (inFile)
    {
        inFile.get(ch);     // this is the first char grab
        Node *newNode;
        newNode = new Node;
        newNode->value = ch;// the char is stored
        newNode->value = 1; // and the first occurence has been recorded
        newNode->left = NULL; // in this use, the left most node is first, so if there is nothing to the left of this, then it is first

        while (inFile) {
            inFile.get(ch);
        }
        inFile.close();
    }
	else
        cout << "cannot open " << path << endl;

	// - count/store unique chars
	// - how often the chars occur
	// - something holding these char/number structs
	// - linking the structs together into a tree
}

void HuffmanTree::huffman() {
	// - displaying/finding the huffman code based on depth
}

void HuffmanTree::postOrder() {
	// output the post-order traversal of the tree
}

void HuffmanTree::encode() {
	// convert the loaded file into huffman code and write to a .hzip file
	// use 0's to pad the rest of the document to be a multiple of 8
}
