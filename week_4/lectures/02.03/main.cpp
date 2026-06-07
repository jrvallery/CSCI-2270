//Singly linked lists, each element (node) contains the data stored in the node and a pointer to the next node in the list.
//Once you reach a null pointer you reach the end of the list
//Index 0 is a "Head" pointer which points to the inital node.


/*
Linked List as ADT
    Initialize the list
    Determine whether the list is empty
    Print the list
    Find the length of the list
    Destroy the list
    Retrieve the info contained in the first node
    retrieve the info contained in the last node
    Insert and delete items from LL
    copy Items of the LL



Define class LinkedListType
*/


#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next; //Always intialize to null
};


class LinkedList {
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void insertNode(int leftValue, int value);
    Node* search(int targetValue);
    void traverse();
    void deleteNode();
    void deleteList();
};

LinkedList::LinkedList() {
    Node *head = new Node;
    this->head = head;
}

Node* LinkedList::search(int targetValue){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->value == targetValue){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::insertNode(int leftValue, int value){
    
}


void LinkedList::traverse(){

}
void LinkedList::deleteNode(){

}
void LinkedList::deleteList(){

}


int main(){
    Node* head = new Node; //Nodes always want to be stored on the heap
    head->value = 10;
    head->next = new Node; //Intialize empty pointer to null

    delete head; //Should delete all alocated nodes
    return 0;
}