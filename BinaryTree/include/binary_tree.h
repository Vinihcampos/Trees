#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <iostream>

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
		void remove(Node & node);

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
		int calculate_height() { calculate_height(node); }
};

#include "../src/binary_tree.inl"
#endif
