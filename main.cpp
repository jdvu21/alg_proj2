#include "huffman.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    HuffmanTree myTree;

	string path;

	if (argc > 1) {
		path = argv[1];
	}

	myTree.reader(path);
	return 0;
}
