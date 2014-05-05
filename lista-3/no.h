#ifndef NO_H
#define NO_H

using namespace std;

class No{

public:
	char chave;
	int peso;
	No *direito, *esquerdo;

	No();
	No(char, int);
	~No();
	bool isFolha();
	int getPeso();
};

#endif