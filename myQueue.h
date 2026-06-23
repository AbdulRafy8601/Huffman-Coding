#pragma once
#include <iostream>
#include "HuffmanNode.h"
class HuffmanNode;

using namespace std;
class myQueue
{
    HuffmanNode **arr;//like huffman nodes[256] in my code
    int maxSize;
    int currentSize;

public:
    myQueue(int);
    ~myQueue();
    void enqueue(HuffmanNode *);
    HuffmanNode *dequeue();
    bool isFull();
    bool isEmpty();
};


inline myQueue::myQueue(int s)
{
    maxSize = s;//donot need to use s as variable rather use s=256
    currentSize = 0;
    arr = new HuffmanNode *[s];// use 256 in place of s
}

inline void myQueue::enqueue(HuffmanNode *n)
{
    if (isFull()) 
        return;

    int i = currentSize - 1;
    while (i >= 0 && arr[i]->getFrequency() >= n->getFrequency())
    {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = n;
    currentSize++;
}

inline bool myQueue::isFull()//useless statement: Remove it, because it will never be true
{
    return currentSize == maxSize;//It will run when our current size will reaches our max size, no more sorting needed ,it will become useful when we will dynamically decide the size of arr like, the size should be 3 in case of text file consists of aaabbcccc
}

inline bool myQueue::isEmpty()
{
    return currentSize == 0;
}

inline HuffmanNode *myQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return nullptr;
    }

    HuffmanNode *temp = arr[0];

    for (int i = 0; i < currentSize - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    currentSize--;//as the current size decreases, so it takes less time than my code to get the node to build tree.
    return temp;
}

inline myQueue::~myQueue()
{
    for (int i = 0; i < currentSize; i++)
        delete arr[i];

    delete[] arr;
}

// #endif