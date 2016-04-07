#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <iostream>

template < typename T >
class BinaryTree{

	private:
		
		struct Node{
			int key;
			T data;
			Node * left;
			Node * right;

			Node(int _key = 0, T _data = T(), Node * _left = nullptr, Node * _right = nullptr) : 
				key {_key}, data {_data}, left {_left}, right {_right}{}			
		};

		Node * node;

		void init();

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
		void insert();

		/**
		*	Remove one element of tree
		**/
		void remove();

		/**
		*	Clear the tree
		**/
		void clear();

}