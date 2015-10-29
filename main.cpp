#include "huffcode.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sys/stat.h>

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
    target->displayPostOrder();

    string code = target->getEncodedData(); // our encoded string

    string zeros = "00000000"; // 8 zeros
    if (code.size() % 8 != 0) {
    	code += zeros.substr(0,8 - code.size() % 8);
    }

    // ofstream myfile;
    // myfile.open(path.c_str()); // creates a new file with the name of path.hzip

    ifstream myfile2;
    myfile2.open (path.c_str(), ios::binary);

    struct stat filestatus;
    stat(path.c_str(), &filestatus );
    long fsize = filestatus.st_size; //get the size of the file in bytes

    char c[fsize];
    myfile2.read(c, fsize);

    string s = "";
    long count = 0;
    while(count<fsize) {
     	unsigned char uc =  (unsigned char) c[count];
      	string p = ""; //a byte string
      	for (int j=0; j<8 && uc>0; j++) {
		   	if (uc%2==0)
            	p="0"+p;
         	else
            	p="1"+p;
        uc=uc>>1;
      }
      p = zeros.substr(0, 8-p.size()) + p; //pad 0s to left of the binary code if needed
      s+= p;
      count++;
   }
   myfile2.close();

   path = path.substr(0, path.find(".")); // truncates the path name passed in earlier
   path += ".hzip";

   ofstream myfile;
   myfile.open(path.c_str(), ios::binary);
   
   if (code.size()%8!=0)
      code += zeros.substr(0, 8-code.size()%8);
   
   int b; 
   for (int i = 0; i < code.size(); i+=8) {
      b = 1;
      for (int j = 0; j < 8; j++) {
         b = b<<1;
         if (code.at(i+j) == '1')
           b+=1;
      }
      char c = (char) (b & 255);
      myfile.write(&c, 1);  
   }
   myfile.close();

   	// path = path.substr(0, path.find(".")); // truncates the path name passed in earlier
    // path += ".hzip";

    // int b;
    // for (int i = 0; i < code.size(); i += 8) {
    // 	b = 1;
    // 	for (int j = 0; j < 8; j++) {
    // 		b = b << 1;
    // 		if (code.at(i+j) == '1') {
    // 			b += 1;
    // 		}
    // 	}
    // 	char c = (char) (b & 255);
    // 	myfile.write(&c, 1);
    // }

    // myfile.close();
    return 0;
}
