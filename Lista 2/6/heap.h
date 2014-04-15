#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <vector>

const int MAX = 1000000001;

using namespace std;

class Heap{
	int elements[MAX];
	int last_pos;

	int get_father(int pos);
	int get_left_son(int pos);
	int get_right_son(int pos);

	void shift_up(int pos);

public:

	Heap();
	Heap(vector<int> v);
	~Heap();
	
	void insert(int num);
	void remove(int num);
	// void search(int key);

	int extract_max();
	void heapify(int key);
	void build_a_heap();

	vector<int> heap_sort();

	void print();
};

#endif