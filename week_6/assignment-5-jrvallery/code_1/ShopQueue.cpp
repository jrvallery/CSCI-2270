#include "ShopQueue.hpp"
#include <iostream>

using namespace std;

ShopQueue::ShopQueue() {
   this->queueFront = nullptr;
   this->queueEnd = nullptr;
}

ShopQueue::~ShopQueue() {
   while(!isEmpty()){
      dequeue();
   }
   delete queueFront;
}

/**
 * Checks if the shopqueue is empty or not
 * @returns Whether its empty or not
 */ 
bool ShopQueue::isEmpty() {
   // TODO
   if(queueFront == nullptr){
      return true;
   }
   return false;
}

/**
 * Looks at the shopqueue and returns the most 'urgent' order on the queue. No elements should be removed.
 * @return A customer order
 */
CustomerOrder* ShopQueue::peek() {
   // TODO
   if(queueFront == nullptr){
      cout << "Queue empty, cannot peek!\n";
   }
   return queueFront;
}

/**
 * Adds the customers to the queue.
 * @param name The name of the customer to add.
 * @param num_pancakes The number of pancakes to add
 * @param type_of_pancake The type of pancake to add. 
 * 
 */
void ShopQueue::enqueue(string name, int num_pancakes, int type_of_pancake) {
   // TODO
   CustomerOrder *newEnd = new CustomerOrder{name, num_pancakes, type_of_pancake, nullptr};

   if(queueFront == nullptr){
      queueEnd = newEnd;
      queueFront = newEnd;
   }
   else{
      queueEnd->next = newEnd;
      queueEnd = newEnd;
   }
}

void ShopQueue::dequeue() {
   // TODO
   if(isEmpty()){
      cout << "Queue empty, cannot dequeue!" << endl;
      return;
   }
   CustomerOrder *temp = queueFront;
   queueFront = queueFront->next;
   delete temp;

   if(queueFront == nullptr){
      queueEnd = nullptr;
   }
}

/**
 * Should return the total number of customers in the queue. 
 * @returns The total number of elements
 */
int ShopQueue::queueSize(){
   // TODO
   CustomerOrder *temp = queueFront;
   int count = 0;
   while(temp != nullptr){
      temp = temp->next;
      count++;
   }
   return count;
}

/**
 * Just returns the end of the queue. Used for testing. Do not touch! :)
 */ 
CustomerOrder* ShopQueue::getQueueEnd(){
   return queueEnd;
}