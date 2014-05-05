#ifndef ARVORE_H
#define ARVORE_H

#include "no.h"

class ArvoreBinaria{

	No *raiz;

public:
	ArvoreBinaria(No *raiz);
	~ArvoreBinaria();

	int getPeso();
};

#endif