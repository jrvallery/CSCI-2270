#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>
#include<iostream>


using namespace std;

//Each instance of a item in the PQ is of type itemInfo
struct ItemInfo{
    string characterName;
    string itemName;
    int damage; //Damage is the priority factor in the PQ. Higher damage means higher priority
    string comment;
};

class PriorityQ
{
      // pointer to array of elements in heap
      ItemInfo *heapArr;
      // maximum possible size of  heap
      int capacity;
      // Current number of elements in  heap
      int currentSize;

public:
      PriorityQ();
      PriorityQ(int capacity);
      int parent(int index);
      int leftChild(int index);
      int rightChild(int index);

      ItemInfo* peek();
      void heapify(int index);
      void pop();
      void insertElement(ItemInfo value);
      void printHelper(int i);
      void print();
      bool isEmpty(){return currentSize==0;};
      void deleteKey(string item);
};
#endif
