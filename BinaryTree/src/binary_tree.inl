#include "binary_tree.h"
#include <iostream>
#include <queue>

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

template <typename T>
void BinaryTree<T>::visite_node(Node *_node){
	cout << _node->info << ": " << _node->height << "\n";
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
	if(_key > _node->key){
		if(_node->right == nullptr){
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return next(_key, _node->right, _aux);
	}else if(_key < _node->key){
		_aux = _node;
		if(_node->left == nullptr) {
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return next(_key, _node->left, _aux);
	}else{
		if(_node->right == nullptr){
			if(_aux == nullptr) return _node;
			else return _aux;
		}else return next(_key, _node->right, _aux);
	}
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