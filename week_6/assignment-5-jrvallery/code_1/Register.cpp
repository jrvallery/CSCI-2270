#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Register.hpp"


using namespace std;

Register::Register(){
   top = 0;
}

/*
 * If the register is full or not
 * @returns 
 */
bool Register::isFull(){
   // TODO
   return (top == SIZE);
}

/*
 * Adds money to stack.
 * @param money: the type of pancake's price times the quantity
 */
void Register::push( int money ){
   // TODO
   if(isFull()){
      cout << "Stack overflow: " << endl;
      return;
   }
   a[top] = money;
   top++;
}


/*
 * Checks if stack is full. 
 * @returns a bool
 */
bool Register::isEmpty(){
   // TODO
   return (top == 0);
}

/*
 * Looping through the stack array to display amounts
 */
void Register::disp(){
   // TODO
   if(isEmpty()){
      cout << "Stack empty, cannot print!" << endl;
      return;
   }
   cout << "top = [" << a[top] << "]" << endl;
   
   for(int i = top - 1; i >= 0; i--){
      cout << a[i] << endl;
   }
}

int Register::pop(){
   // TODO
   if(isEmpty()){
      cout << "Stack empty, cannot pop an item!" << endl;
      return -1;
   }
   
   top--;
   int val = a[top];
   return val;
}