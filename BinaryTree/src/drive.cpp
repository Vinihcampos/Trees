#include <iostream>
#include <string>
#include "binary_tree.h"
#include <utility>

using namespace std;

int main(){
	BinaryTree<int> bt;

	pair<int, int> * list = new pair<int, int>[7];

	for(int i = 0; i < 7; ++i){
		list[i].first = i+1;
		list[i].second = i+1;
	}

	bt.insertList(list, 0, 6);
	bt.pre_order_recursive();

	/*bt.insert(50, 50);
	bt.insert(35, 35);	
	bt.insert(70, 70);
	bt.insert(25, 25);
	bt.insert(40, 40);
	bt.insert(30, 30);
	bt.insert(65, 65);
	bt.insert(90, 90);
	bt.insert(80, 80);

	bt.simetric_order_recursive();

	cout << "Height tree: " << bt.calculate_height() << endl;

	cout << bt.search(30)->info << endl;

	cout << bt.next(40)->key << endl;*/

	/*bt.simetric_order_recursive();

	cout<<endl;
	bt.remove(50);

	bt.simetric_order_recursive();

	bt.remove(65);

	cout<<endl;
	bt.simetric_order_recursive();

	cout<<bt.max_key()<<endl;
	cout<<bt.max_key()<<endl;*/

	return 0;
}