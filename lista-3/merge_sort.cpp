#include <iostream>
#include <vector>

using namespace std;

//função de comparação para usar no merge
bool compare(const int a, const int b){
	if (a>b){
		return false;
	}
	return true;
}

void print(const vector<int> &v){
	for (int i = 0; i < (int)v.size(); ++i)
	{
		if(v[i]!=0)
			cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> merge_sort(const vector<int> &v){

	if(v.size() <=1){
		// print(v);
		return v;
	}

	int meio = v.size()/2;

	vector<int> esquerda(v.begin(), v.begin()+meio);
	vector<int> direita(v.begin()+meio, v.end());

	esquerda = merge_sort(esquerda);
	direita = merge_sort(direita);

	vector<int> ordenado(v.size());
	cout << "Vetor: "; print(v);
	cout << "Esquerda: "; print(esquerda);
	cout << "Direita: "; print(direita);

	// merge(esquerda.begin(), esquerda.end(), direita.begin(), direita.end(),ordenado.begin());

	vector<int>::iterator  it_e = esquerda.begin();
	vector<int>::iterator  it_d = direita.begin();

	while(it_e != esquerda.end() && it_d != direita.end()){
		if(*it_e < *it_d){
			ordenado.push_back(*it_e);
			it_e++;
		} else {
			ordenado.push_back(*it_d);
			it_d++;
		}
	}

	while(it_e != esquerda.end()){
		ordenado.push_back(*it_e);
		it_e++;
	}

	while(it_d != direita.end()){
		ordenado.push_back(*it_d);
		it_d++;
	}

	cout << "Ordenado: "; print(ordenado);
	cout << endl;

	return ordenado;
}

int main(){
	int myints[] = {16,2,77,29,10};
	vector<int> numeros(myints, myints + sizeof(myints)/sizeof(int));

	print(numeros);

	print(merge_sort(numeros));

	return 0;
}