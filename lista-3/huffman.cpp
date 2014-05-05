#include <huffman.h>

Huffman::Huffman(string frase){
	this->seed = frase;
	contarPesos();
	montarArvore();
}