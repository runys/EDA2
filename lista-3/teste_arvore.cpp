#include <iostream>

#include "arvore_binaria.h"

using namespace std;

int main(){

	No *raiz = new No('a',1);
	ArvoreBinaria *teste = new ArvoreBinaria(raiz);

	cout << teste->getPeso() << endl;

	return 0;
}