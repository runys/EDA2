#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

void radix_counting(vector<int> *v, int size) {
    int b[size];
    int maior = v->at(0);
    int exp = 1;
 
    for (int i = 0; i < size; i++) {
        if (v->at(i) > maior)
    	    maior = v->at(i);
    }
    
 	//enquanto não chega na ultima casa do ultimo digito
    while (maior/exp > 0) {
        int balde[10] = { 0 };
        //aplicando counting sort
    	for (int i = 0; i < size; i++){
    	    balde[(v->at(i) / exp) % 10]++; 
    	}
    	for (int i = 1; i < 10; i++){
    	    balde[i] += balde[i - 1];
    	}
    	//coloca na ordem
    	for (int i = size - 1; i >= 0; i--){
    	    b[--balde[(v->at(i) / exp) % 10]] = v->at(i);
    	}
    	//passa do auxiliar para o principal
    	for (int i = 0; i < size; i++){
    	    v->at(i) = b[i];
    	}
    	exp *= 10;
    }
}

int main(){
	
	srand(time(NULL));
	clock_t t;
	vector<int> *v = new vector<int>;

	for (int i = 0; i < 7; ++i){
		int num = pow(10,i);
		for (int i = 0; i < num; ++i){
			v->push_back((rand() % 10000000)+10000000);
		}
		t = clock();
		radix_counting(v,num);
		t = clock() - t;
		cout << num << " : " << fixed << setprecision(6) << (((double)t)/CLOCKS_PER_SEC)/10 << endl;
	}

	return 0;
}

