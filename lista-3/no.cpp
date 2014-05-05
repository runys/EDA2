#include "no.h"

using namespace std;

No::No(){
	this->esquerdo = this->direito = NULL;
}

No::No(char chave, int peso){
	this->chave = chave;
	this->peso = peso;
	this->esquerdo = this->direito = NULL;
}

No::~No(){
	free(esquerdo);
	free(direito);
}

bool No::isFolha(){

	if(this->esquerdo == NULL && this->direito == NULL)
		return true;

	return false;
}

int No::getPeso(){
	return this->peso;
}