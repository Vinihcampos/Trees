#include "binary_tree.h"
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

template < typename T >
BinaryTree<T>::BinaryTree(){
	node = nullptr;
}

template < typename T >
BinaryTree<T>::~BinaryTree(){
	delete node;
}

template < typename T >
typename BinaryTree<T>::Node * BinaryTree<T>::search(int _key){
	Node * _node = node;
	while(_node != nullptr && _node->key != _key){
		if(_key > _node->key){
			_node = _node->right;
		}else if(_key < _node->key){
			_node = _node->left;
		}
	}
	return _node;
}

template < typename T>
void BinaryTree<T>::insert(int _key, T _info){
	Node * _node = new Node(_key, _info);
	if(node == nullptr) node = _node;
	else{
		Node * it_node = node;
		while((_node->key > it_node->key && it_node->right != nullptr) || (_node->key < it_node->key && it_node->left != nullptr) ){
			if(_node->key > it_node->key){
				it_node = it_node->right;					 
			}else if(_node->key < it_node->key){
				it_node = it_node->left;
			}
		}
		if(_node->key > it_node->key){
			it_node->right = _node;					 
		}else if(_node->key < it_node->key){
			it_node->left = _node;
		}		
	}
}

template < typename T >
void BinaryTree<T>::transplant(Node * previous, Node * current, Node * pivot){
	if(previous == nullptr){
		node = pivot;
	}else if(current == previous->left){
		previous->left = pivot;
	}else{
		previous->right = pivot;
	}
}

template < typename T >
void BinaryTree<T>::remove(int _key){
	Node * current = node;
	Node * previous = nullptr;

	while(current != nullptr && current->key != _key){
		if(_key > current->key){
			previous = current;
			current = current->right;
		}else if(_key < current->key){
			previous = current;
			current = current->left;
		}
	}

	if(current != nullptr){
		if(current->left == nullptr){
			transplant(previous, current, current->right);
		}else if(current->right == nullptr){
			transplant(previous, current, current->left);
		}else{
			Node * _next = next(current->key);
			if(current->right != _next){
				int key = _next->key;
				Node * _current = node;
				Node * previous_next = nullptr;

				while(_current != nullptr && _current->key != key){
					if(key > _current->key){
						previous_next = _current;
						_current = _current->right;
					}else if(key < _current->key){
						previous_next = _current;
						_current = _current->left;
					}
				}
				
				transplant(previous_next, _next, _next->right);
				_next->right = current->right; 
			}
			transplant(previous, current, _next);
			_next->left = current->left;
		}
	}
}

/*template < typename T>
void BinaryTree<T>::remove(int _key){
	Node * current = node;
	Node * previous = nullptr;
	while(current != nullptr && current->key != _key){
		if(_key > current->key){
			previous = current;
			current = current->right;
		}else if(_key < current->key){
			previous = current;
			current = current->left;
		}
	}
	if(current != nullptr){
		if(current->right == nullptr && current->left == nullptr){
			if(current == previous->left) previous->left = nullptr;
			else previous->right = nullptr;
			delete current;
		}else if(current->right == nullptr && current->left != nullptr){
			if(current == previous->left) previous->left = current->left;
			else previous->right = current->left;
			delete current;
		}else if(current->right != nullptr && current->left == nullptr){
			if(current == previous->left) previous->left = current->right;
			else previous->right = current->right;
			delete current;
		}else{
			Node * pivot = current->left;
			previous = nullptr;

			while(pivot->right != nullptr) {
				previous = pivot;
				pivot = pivot->right;
			}

			if(pivot->left == nullptr && previous != nullptr) previous->right = nullptr;
			else if(pivot->left != nullptr && previous != nullptr) previous->right = pivot->left;
			
			pivot->right = current->right;
			pivot->left = previous;				
			
			cout<<"Key current - 1: " << current->key <<endl;
			cout<<"Key left: " << current->left->key <<endl;
			cout<<"Key right: " << current->right->key <<endl;

			current = pivot;

			cout<<"Key current - 1: " << current->key <<endl;
			cout<<"Key left: " << current->left->key <<endl;
			cout<<"Key right: " << current->right->key <<endl;
		}
	}

}*/

template <typename T>
void BinaryTree<T>::visite_node(Node *_node){
	cout << _node->key << " ";
}

template <typename T>
void BinaryTree<T>::pre_order_recursive(Node * _node){
	if(_node != nullptr){
		visite_node(_node);
		if(_node->left != nullptr){
			pre_order_recursive(_node->left);
		}
		if(_node->right != nullptr){
			pre_order_recursive(_node->right);
		}
	}
}

template <typename T>
void BinaryTree<T>::pos_order_recursive(Node * _node){
	if(_node != nullptr){
		if(_node->left != nullptr){
			pos_order_recursive(_node->left);
		}
		if(_node->right != nullptr){
			pos_order_recursive(_node->right);
		}
		visite_node(_node);
	}
}

template <typename T>
void BinaryTree<T>::simetric_order_recursive(Node * _node){
	if(_node != nullptr){
		if(_node->left != nullptr){
			simetric_order_recursive(_node->left);
		}
		visite_node(_node);
		if(_node->right != nullptr){
			simetric_order_recursive(_node->right);
		}
	}
}

template < typename T >
void BinaryTree<T>::search_by_level(Node * node){
	queue<Node*> nodes;
	nodes.push(node);
	while(!nodes.empty()){
		if(nodes.front()->left != nullptr) 
			nodes.push(nodes.front()->left);
		if(nodes.front()->right != nullptr)
			nodes.push(nodes.front()->right);
		visite_node(nodes.front());
		nodes.pop();
	}
}

template < typename T >
int BinaryTree<T>::calculate_height(Node * _node){
	if(_node->left != nullptr){
		_node->height = calculate_height(_node->left);
	}
	if(_node->right != nullptr){
		int temp = calculate_height(_node->right);
		_node->height < temp ? _node->height = temp : _node->height;
	}
	_node->height++;
	visite_node(_node);
	return _node->height;
}

template < typename T >
typename BinaryTree<T>::Node * BinaryTree<T>::next(int _key, Node * _node, Node * _aux){
	if(_key < _node->key){
		_aux = _node;
		if(_node->left != nullptr) return next(_key, _node->left, _aux); 
	}else{
		if(_node->right != nullptr)	return next(_key, _node->right, _aux);
	}

	return _aux;
}

template < typename T >
typename BinaryTree<T>::Node * BinaryTree<T>::previous(int _key, Node * _node, Node * _aux){
	if(_key > _node->key){
		_aux = _node;
		if(_node->right == nullptr){
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return previous(_key, _node->right, _aux);
	}else if(_key < _node->key){
		if(_node->left == nullptr) {
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return previous(_key, _node->left, _aux);
	}else{
		if(_node->left == nullptr){
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return previous(_key, _node->left, _aux);
	}
} 

template < typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::max(Node * _node, Node * previous){
	Node * _temp = _node;
	previous = nullptr;
	while(_temp->right != nullptr) {
		previous = _temp;
		_temp = _temp->right;
	}

	return _temp;
}

template < typename T >
int BinaryTree<T>::max_key(){
	Node * _temp = node;
	while(_temp->right != nullptr) _temp = _temp->right;
	
	int key = _temp->key; 

	return key;
}

template < typename T >
void BinaryTree<T>::insertList(pair<int, T> * list, int l, int h){
	if(l <= h){
		int med = (l + h)/2;
		insert(list[med].first, list[med].second);
		insertList(list, l, med - 1);
		insertList(list, med + 1, h);
	}
} 