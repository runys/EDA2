#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>

class Huffman{

	string seed;

	void contarPesos();
	void montarArvore();

public:
	Huffman(string frase);
	~Huffman();

	// void showDictionary();
	// string codedSentence();
};

#endif