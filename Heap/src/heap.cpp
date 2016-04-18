#include <iostream>

using namespace std;

template <typename T>
struct Node{
	
	int key;
	T info;
	int height;

	Node(int _key = -1, T _data = T()) : 
		key {_key}, info {_data}, height{0}{}			
};

template < typename T>
void swap(Node<T> * n1, Node<T> * n2){
	Node<T> aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

template <typename T>
void fall(Node<T> * list, int i, int max){
	int l = 2 * i + 1;
	if(l <= max){
		int r = l + 1;
		if(r <= max){
			if(list[r].key > list[l].key) l++;
		}
		if(list[i].key < list[l].key){
			swap(list[i], list[l]);
			fall(list, l, max);
		}
	}
}

template <typename T>
void fall_ite(Node<T> * list, int i, int max){
	int left = (2*i)+1;
	int x;
	while(left <= max && list[i].key < list[left].key){
		int right = left + 1;
		if(right <= max){
			if(list[left].key < list[right].key) left++;
		}
		if(list[i].key < list[left].key){
			swap(list[i], list[left]);
			i = left;
			left = (i*2)+1;
		}
	}
}

template < typename T >
void climb(Node<T> * list, 	int & index){
	int parent = (index - 1)/2;
	if(parent >= 0 && index > 0){		
		if(list[parent].key < list[index].key){
			swap(list[parent], list[index]);
			climb(list, parent);
		}
	}
}

template < typename T >
void climb_ite(Node<T> * list, 	int index){
	int parent = (index - 1)/2;
	int x;
	while(parent >= 0 && index > 0 && list[parent].key < list[index].key){
		if(list[parent].key < list[index].key){
			swap(list[parent], list[index]);
			index = parent;
			parent = (index - 1)/2;
		}
	}
} 

template < typename T >
void remove(Node<T> * list, int & max){
	if(max > 0){
		swap(list[0], list[max]);
		--max;
		fall(list, 0, max);
	}
}

template < typename T >
void insert(Node<T> * list, int & max, int key, T info){
	++max;
	list[max].key = key;
	list[max].info = info;
	climb_ite(list, max);
}

template < typename T >
void priority(Node<T> * list, int & max, int index, int newValue){
	list[index].key = newValue;
	if((index-1)/2 >= 0 && list[(index-1)/2].key < list[index].key){
		climb_ite(list, index);
	}else if((2*index)+1 < max && list[(2*index)+1].key > list[index].key){
		fall(list, index, max);
	} 
} 

int main(){
	
	Node<int> * lista = new Node<int>[10];
	lista[0].key = 1;
	lista[1].key = 14;
	lista[2].key = 10;
	lista[3].key = 8;
	lista[4].key = 7;
	lista[5].key = 9;
	lista[6].key = 3;
	lista[7].key = 2;
	lista[8].key = 4;

	int max = 8;

	for(int i = 0; i <= max; ++i){
		cout<<lista[i].key<<" "; 
	}
	cout<<endl;

	fall_ite(lista, 0, max);

	for(int i = 0; i <= max; ++i){
		cout<<lista[i].key<<" "; 
	}
	cout<<endl;

	return 0;
}