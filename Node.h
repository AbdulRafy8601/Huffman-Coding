#pragma once
struct Node {//unneceassry to use in separate files, we should define the following attributes inside the class
	unsigned char data;
	int freq;
	Node* leftChild;
	Node* rightChild;


};