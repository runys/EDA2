#ifndef ARVORE_RB_H
#define ARVORE_RB_H

#include "no.h"

class ArvoreRedBlack{

	No* raiz;

	void insercao_caso1(No *n);
	void insercao_caso2(No *n);
	void insercao_caso3(No *n);
	void insercao_caso4(No *n);
	void insercao_caso5(No *n);

public:

	ArvoreRedBlack();
	~ArvoreRedBlack();

	No* avo(No *n);
	No* tio(No *n);
	void inserir(int valor);
};


#endif