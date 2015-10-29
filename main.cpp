#include "huffcode.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
	string path;

	if (argc > 1) { // will only accept one parameter to be set as the file path
		path = argv[1];
	}

	std::ifstream t(path.c_str());
	std::string contents((std::istreambuf_iterator<char>(t)),
					std::istreambuf_iterator<char>());

	HuffCode* target = new HuffCode(contents);
	target->displayHuffCodes();

	return 0;
}
