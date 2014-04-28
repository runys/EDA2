#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//função de comparação para usar no merge
bool compare(const int a, const int b){
	if (a>b)
		return false;
	return true;
}

void print(const vector<int> &v){
	for (int i = 0; i < (int)v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> merge_sort(const vector<int> &v){

	if(v.size() <=1){
		return v;
	}

	int meio = v.size()/2;

	vector<int> esquerda(v.begin(), v.begin()+meio);
	vector<int> direita(v.begin()+meio, v.end());

	esquerda = merge_sort(esquerda);
	direita = merge_sort(direita);

	vector<int> ordenado(v.size());

	//implementar o merge para mostrar as trocas
	merge(esquerda.begin(), esquerda.end(), direita.begin(), direita.end(),ordenado.begin(), compare);

	return ordenado;
}

int main(){
	int myints[] = {16,2,77,29,10,72,68,44,79,75,59,50,56};
	vector<int> numeros(myints, myints + sizeof(myints)/sizeof(int));

	print(numeros);

	merge_sort(numeros);

	return 0;
}