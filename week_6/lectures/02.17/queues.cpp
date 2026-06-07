/*
QUEUES (CIRCULAR QUEUES)
circular linked list is where the tail node points back the head node.
In the sense of a circualr linked queue we have front and the back
Eveytime a index is added to the queue we move the back away from the front, If we reach the maximum size of the queue, 
we wrap the back to the front 

if(front / back >= arraySize){
    Front / back = 0; //This is an example of wrapping around once array size is reached
}
Another way of implementing this is using %
F/B = (F/B++) % arraySize
example if arraySize = 9
F/B = 1;
1 % 9 = 1; 
2 % 9 = 2; 
3 % 9 = 3; 
4 % 9 = 4; 
5 % 9 = 5; 
6 % 9 = 6; 
7 % 9 = 7; 
8 % 9 = 8;
9 % 9 = 0; back the the begining

*/


#include <iostream>
using namespace std;

int main(){
     
}

struct Node {
  int key;
  Node *next;
};

int deleteNode(int val){
  Node* pres = head;
  Node* prev = NULL;
  if(!pres){
    return -1;
  }
  while(pres->key != val) {
    prev = pres;
    pres = pres->next;
    if(pres == nullptr){
      cout << "Not in LL" << endl;
      return -1;
    }
  }
  prev->next = pres->next;
  delete pres;
  return 1;
}