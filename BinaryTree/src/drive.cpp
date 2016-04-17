#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

int main(){
	BinaryTree<int> bt;

	bt.insert(50, 50);
	bt.insert(35, 35);	
	bt.insert(70, 70);
	bt.insert(25, 25);
	bt.insert(40, 40);
	bt.insert(30, 30);
	bt.insert(65, 65);
	bt.insert(90, 90);
	bt.insert(80, 80);

	/*bt.simetric_order_recursive();

	cout << "Height tree: " << bt.calculate_height() << endl;

	cout << bt.search(30)->info << endl;

	cout << bt.next(40)->key << endl;*/

	bt.simetric_order_recursive();

	cout<<endl;
	bt.remove(50);

	bt.simetric_order_recursive();

	bt.remove(65);

	cout<<endl;
	bt.simetric_order_recursive();

	return 0;
}