#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "heap.h"

using namespace std;

int main(){
	//Para numeros randomicos
	srand(time(NULL));

	//Para contar o tempo
	clock_t t;

	vector<int> v;
	Heap *n_heap;
	Heap *heap;

	cout << "Metodo com vetor" << endl;
	for (int i = 1; i <= 8; ++i){
		int num = pow(10,i);
		cout << num << " : ";
		for (int i = 0; i < num; ++i){
			v.push_back(rand() % num + 1);
		}
		n_heap = new Heap(v);
	
		t = clock();
		v = n_heap->heap_sort();
		t = clock() - t;
		cout << fixed << setprecision(6) << (((double)t)/CLOCKS_PER_SEC)/10 << endl;
		v.clear();
	}

	cout << "Metodo insercao e remocao" << endl;
	for (int i = 1; i <= 8; ++i){
		int num = pow(10,i);
		cout << num << " : ";
		
		heap = new Heap();
		t = clock();
		for (int i = 0; i < num; ++i){
			heap->insert(rand() % num + 1);
		}
		for (int i = 0; i < num; ++i){
			v.push_back(heap->extract_max());
		}
		t = clock() - t;
		cout << fixed << setprecision(6) << (((double)t)/CLOCKS_PER_SEC)/10 << endl;
	}

	return 0;
}