#include "arvore_binaria.h"

ArvoreBinaria::ArvoreBinaria(No *raiz){
	this->raiz = raiz;
}

ArvoreBinaria::~ArvoreBinaria(){

}

int ArvoreBinaria::getPeso(){
	return raiz->getPeso();
}