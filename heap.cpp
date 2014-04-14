#include "heap.h"

Heap::Heap(){
	// assim a raiz do heap é o elemento na posição 1
	this->last_pos = 0;
	this->elements[0] = -1;
}

Heap::Heap(vector<int> v){

	this->last_pos = 0;
	this->elements[0] = -1;

	for(int i=1;i<=(int)v.size();i++){
		this->elements[i] = v[i-1];
		this->last_pos++;
	}
}

Heap::~Heap(){
}

//Métodos privados
int Heap::get_father(int pos){	
	return pos/2;
}

int Heap::get_left_son(int pos){
	return 2*pos;
}

int Heap::get_right_son(int pos){
	return 2*pos+1;
}

void Heap::shift_up(int pos){
	//Ao chegar na raiz não faz nada
	if(pos==1){
		return;
	}
	//se o elemento for maior que o pai dele, troca de posição com o pai
	else if(this->elements[pos] > this->elements[get_father(pos)]){
		int temp = this->elements[pos];
		this->elements[pos] = this->elements[get_father(pos)];
		this->elements[get_father(pos)] = temp;

		shift_up(get_father(pos));
	}
}

//Metodos publicos

void Heap::insert(int num){
	if(this->last_pos < 101){
		//insere ao final
		this->last_pos++;
		this->elements[last_pos] = num;

		//compara com o valor do pai, se for maior faz a troca entre eles
		shift_up(this->last_pos);
		// print();
	}
}

void Heap::print(){
	for(int i = 1; i <= this->last_pos; i++){
		cout << this->elements[i] << " ";
	}
	cout << endl;
}

void Heap::heapify(int key){
	// cout << "# Heapify no elemento " << this->elements[key] << endl;
	//se não tiver filhos, não faz nada
	//tem q ter pelo menos o filho da esquerda
	if(get_left_son(key) > this->last_pos){
		// cout << "O elemento " << this->elements[key] << " nao possui filhos." << endl;
		return;
	}
	//ve qual o maior valor e troca de lugar. se houver troca faz heapify de novo
	else{
		int left = get_left_son(key);
		int right = get_right_son(key);
		// cout << "Filhos de " << this->elements[key] << ": e(" << this->elements[left] << ") d(" << this->elements[right] << ")" << endl;
		//se o pai for maior q o filho da esquerda e da direita não faz troca
		if(this->elements[key] > this->elements[left] && this->elements[key] > this->elements[right]){
			// cout << this->elements[key] << "eh maior que e(" << this->elements[left] << ") e que d(" << this->elements[right] << ")" << endl;
			return;
		}
		else{
			//se o filho da esquerda for maior que o da direita
			if(this->elements[left] > this->elements[right]){
				// cout << "Trocando " << this->elements[key] << " com o " << this->elements[left] << endl;
				//troca o filho da esquerda com o pai
				int temp = this->elements[left];
				this->elements[left] = this->elements[key];
				this->elements[key] = temp;
				//chama heapify no filho da esquerda
				// print();
				heapify(left);
			}else{
				// cout << "Trocando " << this->elements[key] << " com o " << this->elements[right] << endl;
				//troca o filho da direita com o pai
				int temp = this->elements[right];
				this->elements[right] = this->elements[key];
				this->elements[key] = temp;
				// print();
				//chama heapify no filho da direita
				heapify(right);
			}			
		}
	}
}

int Heap::extract_max(){
	
	if(this->last_pos){
		int maximo = this->elements[1];
		// cout << "# Extraido o primeiro elemento: " << maximo << endl;
		//remover o primeiro elemento
		remove(1);
		return maximo;
	}
	
	return -1;
}

void Heap::remove(int pos){
	if(this->last_pos == pos){
		this->last_pos--;
	}else{
		// cout << "# Removendo o elemento na pos \"" << pos << "\" de valor \"" << this->elements[pos] << "\"" << endl;
		//troca o primeiro com o ultimo
		int temp = this->elements[pos];
		this->elements[pos] = this->elements[this->last_pos];
		this->elements[this->last_pos] = temp;
		// cout << "Trocado o primeiro e o ultimo elemento: "; print();
		//apaga o ultimo
		this->elements[this->last_pos] = -1;
		this->last_pos--;
		// cout << "Ultimo apagado, agora o heap eh: "; print();
		//chama o heapify no primeiro elemento
		// cout << "Chamando heapify() no elemento na posicao: " << pos << endl;
		heapify(pos);
	}
}

void Heap::build_a_heap(){
	for (int i = this->last_pos/2; i > 0; i--){
		heapify(i);
	}	
}

vector<int> Heap::heap_sort(){
	build_a_heap();

	vector<int> ordenado;
	int temp_last_pos = this->last_pos;
	for (int i = 0; i < temp_last_pos; ++i){
		ordenado.push_back(extract_max());
	}

	return ordenado;
}
