#ifndef NO_H
#define NO_H

class No{
public:
	bool vermelho;
	int valor;

	No();
	~No();
	void trocarCor();
	bool isPreto();
	bool isVermelho();
};

#endif