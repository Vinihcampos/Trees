#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <utility>
#include <iostream>
using namespace std;

template < typename T >
class BinaryTree{

	private:
		
		struct Node{
			int key;
			T info;
			Node * left;
			Node * right;
			int height;

			Node(int _key = 0, T _data = T(), Node * _left = nullptr, Node * _right = nullptr) : 
				key {_key}, info {_data}, left {_left}, right {_right}, height{0}{}			
		};

		Node * node;

		void init();
		void pre_order_recursive(Node * _node);
		void simetric_order_recursive(Node * _node);
		void pos_order_recursive(Node * _node);
		void search_by_level(Node * _node);
		int calculate_height(Node * _node);
		Node * next(int _key, Node * _node, Node * _aux);
		Node * previous(int _key, Node * _node, Node * _aux);
		void transplant(Node * previous, Node * current, Node * pivot);

	public:

		/**
		*	Constructor
		**/
		BinaryTree();


		/**
		*	Destructor
		**/
		~BinaryTree();


		/**
		*	Insert one element on tree
		**/
		void insert(int _key, T _info);

		/**
		*	Remove one element of tree
		**/
		void remove(int _key);

		/**
		*	Search an element
		**/
		Node * search(int _key);

		/**
		*	Clear the tree
		**/
		void clear();

		/**
		*	Print the _node's info
		**/
		void visite_node(Node * _node);

		/**
		*	Travel the tree at pre_order
		**/
		void pre_order_recursive(){ pre_order_recursive(node); }

		/**
		*	Travel the tree at simetrical_order
		**/
		void simetric_order_recursive(){ simetric_order_recursive(node); }

		/**
		*	Travel the tree at pos_order
		**/
		void pos_order_recursive(){ pos_order_recursive(node); }

		/**
		*	Travel the tree at levels
		**/
		void search_by_level() { search_by_level(node); }

		/**
		*	Calculate the height of each node of tree
		**/
		int calculate_height() { return calculate_height(node); }

		/**
		*	Search the next node of pivot
		**/
		Node * next(int _key) { Node * _aux = nullptr; return next(_key, node, _aux); };

		/**
		*	Search the next node of pivot
		**/
		Node * previous(int _key) { Node * _aux = nullptr; return previous(_key, node, _aux); };

		/**
		*	Search the max key of 
		**/
		Node * max(Node * _node, Node * previous = nullptr);

		/**
		*	Search the max key of 
		**/
		int max_key();

		/**
		*	Insert list
		**/
		void insertList(pair<int, T> * list, int l, int h);
};

#include "../src/binary_tree.inl"
#endif
