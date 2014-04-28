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
		// print(v);
		return v;
	}

	int meio = v.size()/2;

	vector<int> esquerda(v.begin(), v.begin()+meio);
	vector<int> direita(v.begin()+meio, v.end());

	esquerda = merge_sort(esquerda);
	direita = merge_sort(direita);

	vector<int> ordenado(v.size());

	// merge(esquerda.begin(), esquerda.end(), direita.begin(), direita.end(),ordenado.begin(), compare);

	while(!esquerda.empty() && !direita.empty()){
		if(esquerda[0] < direita[0]){
			cout << "troca: " << direita[0] << " com " << esquerda[0] << endl;
			ordenado.push_back(esquerda[0]);
			esquerda.erase(esquerda.begin());
		} else{
			cout << "troca: " << esquerda[0] << " com " << direita[0] << endl;
			ordenado.push_back(direita[0]);
			direita.erase(direita.begin());
		}
	}

	ordenado.reserve(ordenado.size() + esquerda.size() + direita.size());

	if(esquerda.size() <=0){
		ordenado.insert(ordenado.end(), direita.begin(), direita.end());
	} else {
		ordenado.insert(ordenado.end(), esquerda.begin(), esquerda.end());
	}

	return ordenado;
}

int main(){
	int myints[] = {16,2,77,29,10};
	vector<int> numeros(myints, myints + sizeof(myints)/sizeof(int));

	print(numeros);

	print(merge_sort(numeros));

	return 0;
}