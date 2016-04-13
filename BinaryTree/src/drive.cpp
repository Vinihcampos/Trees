#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

int main(){
	BinaryTree<int> bt;

	bt.insert(20, 20);
	bt.insert(10, 10);	
	bt.insert(40, 40);
	bt.insert(15, 15);
	bt.insert(30, 30);
	bt.insert(50, 50);
	bt.insert(60, 60);

	cout << "Height tree: " << bt.calculate_height() << endl;

	cout << bt.search(100)->info << endl;

	return 0;
}