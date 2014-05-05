#include <iostream>
#include "huffman.h"

using namespace std;

int main(){

	string frase = "how i met your mother";
	
	Huffman coder = new Huffman(frase);

	coder.showDictionary();

	cout << coder.codedSentence() << endl;


	return 0;
}