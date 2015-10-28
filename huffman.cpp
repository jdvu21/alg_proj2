// Project goals:
// 1. read in the file to be encoded
// 	  construct the huffman tree
// 2. display the huffman code to std output ( a(4):1001 )
// 3. output the post-order traversal of the tree (a1e2@5@6; using @ for interior nodes)
// 4. encode the loaded file and save it to a .hzip file
// 	  use 0's to pad the rest of the document (see example)

#include "huffnode.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void reader() {

	// - count/store unique chars
	// - how often the chars occur
	// - something holding these char/number structs
	// - linking the structs together into a tree
}

void huffman() {
	// - displaying/finding the huffman code based on depth
}

void postOrder() {
	// output the post-order traversal of the tree
}

void encode() {
	// convert the loaded file into huffman code and write to a .hzip file
	// use 0's to pad the rest of the document to be a multiple of 8
}
