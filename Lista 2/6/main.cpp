#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main(){

	Heap *heap = new Heap();

	heap->insert(10);
	heap->insert(20);
	heap->insert(15);
	heap->insert(17);
	heap->insert(30);

	cout << "Heap: "; heap->print();
	
	// heap->extract_max();

	cout << "Resultado: "; heap->print();

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(15);
	v.push_back(17);
	v.push_back(30);

	Heap *n_heap = new Heap(v);

	cout << "Heap: "; n_heap->print();
	n_heap->heap_sort();
	cout << "Resultado: "; n_heap->print();


	return 0;
}