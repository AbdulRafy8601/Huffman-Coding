#pragma once
#include "Node.h"
#include <string>
#include "BinaryCode.h"
#include "SimpleMap.h"
using namespace std;
class myQueue;
class HuffmanNode
{
	Node *root;
	void deleteTree(Node *n)
	{
		if (n == nullptr)
			return;
		deleteTree(n->leftChild);//never run?
		deleteTree(n->rightChild);//never run?
		delete n;//never run?
	}

public:
	HuffmanNode(unsigned char d, int n);
	~HuffmanNode();
	int getFrequency();
	HuffmanNode(HuffmanNode *left, HuffmanNode *right);
	Node *getRoot();
	static HuffmanNode *buildHuffmanTree(myQueue &q);
	void generateCodes(
		Node *root,
		unsigned int currentBits,
		int currentLength,
		SimpleMap &map);
};
