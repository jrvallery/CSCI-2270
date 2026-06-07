/*
Stacks: LAST IN FIST OUT (LIFO) THIS EQUALS FIRST IN LAST OUT (FILO)
think of stacking plates on top of each other, the last plate in the stack will be the first one you put in.

STACK OPPS:
    push() add new element to top of stack
    top() or peek() return top element of stack (would return a value) NEVER WOULD RETURN A POINTER
    pop() removes the top element of the stack
    isFullStack() checks weather stack is full, returns bool
    isEmptyStack() vis versa
    intializeStack() A stack must be empty before we are able to use it

Queues: FIRST IN FIRST OUT (FIFO)
Elements are added to back and elements are deleted from the front
Rear accessed when adding. Front accessed when deleting

Queue ADT:
private:
    head - first item in the queue (next to be proccessed)
    tail - most recent item that was added
    queueSize - # of elements
public:
    init()
    bool isFull()
    bool isEmpty()
    addElement()
    deleteElement()
*/

/*
ASYMPTOTIC ANALYSIS ----> Big O O()

STACK:
    LETS SAY WE TREAT STACKS AS A LINKED LIST
    push() insert a item at the head
    pop() delete at the head of the LL
    
    This means that the stack has a a asymptotic realationship of O(1)

QUEUES:
    WE USE CIRCULAR WRAPPING
    lets say we have an array, intially back and front are both on the same index, as each element joins the line the back moves away from the front,
    Once the back reaches the last element it is then wrapped back around and assigned to the front. So one back == front we know the Queue is full

    When we de Queue from the array we do the opposite and move the front towards that back, once the front == back we then know that the Queue is empty

*/
#include <iostream>
using namespace std;
struct Node
{
    string item;
    Node* next;
};

class Stack {
    private:
        Node *top;
        int count;
    public:
        Stack();
        ~Stack();

        bool isEmpty();
        void push(string newItem); //dynamically allocate new node and push onto stack
        void pop(); //remove node from top of stack and deallocate node's memory
        Node *peek(); //return pointer to the node that corresponds to top of stack
        void disp();
};


Stack::Stack(){
    this->top = nullptr;
}
void Stack::push(string newItem){
    Node *temp = new Node;
    temp->item = newItem;

    if(isEmpty()){
        top = temp;
        top->next = nullptr;
    }
    else{
        temp->next = top;
        top = temp;
    }
    delete temp;
}

void pop(){
    Node *temp = new Node;
    
}
Node* Stack::peek(){
    return top;
}