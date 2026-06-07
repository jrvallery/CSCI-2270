#include "PriorityQueue.hpp"
#include <limits.h>
using namespace std;

void swap(ItemInfo *a, ItemInfo *b)
{
	//dereferencing (a and b) we access the ItemInfo objects they point to and then overwrite 
	//(swaps value at memory address rather then within the function)
	ItemInfo temp = *a;
	*a = *b;
	*b = temp;
}

/*
Constructor for our MinHeap implementation
*/
PriorityQ::PriorityQ() {
    capacity = 50;
    currentSize = 0;
    heapArr = new ItemInfo[capacity];
}
/*
Finds the parent of a node, given its index.
*/
int PriorityQ::parent(int index)
{
    if (index <= 0 || index >= capacity)  
        return -1;

    return (index - 1) / 2;
}

/*
Returns the left child of a node.
*/
int PriorityQ::leftChild(int index)
{
	int li = 2*index + 1;
	if(li < capacity) return li;
	return -1;
}

/*
Returns the right child of a node.
*/
int PriorityQ::rightChild(int index)
{
	int ri = 2*index + 2;
    if (ri < capacity) return ri;
	return -1;
}

ItemInfo* PriorityQ::peek()
{
	if(currentSize == 0) return nullptr;
	return &heapArr[0];
}

void PriorityQ::heapify(int i)
{
	int leftIndex = leftChild(i);
	int rightIndex = rightChild(i);
	int largest = i; //intialize largest to i

	if(leftIndex != -1 && heapArr[leftIndex].damage > heapArr[largest].damage) //compare with heap[largest]
		largest = leftIndex;
		
	if(rightIndex != -1 && heapArr[rightIndex].damage > heapArr[largest].damage) //compare with heap[largest]
		largest = rightIndex;

	if(largest != i){ //Indexs changed
		swap(heapArr[largest], heapArr[i]); //Swap smaller item with larger (bubble down)
		heapify(largest); //recursive heapify call
	}
}

void PriorityQ::insertElement(ItemInfo item)
{
	if(currentSize >= capacity) return; //No room to insert (full)

	int i = this->currentSize;
	heapArr[i] = item;
	currentSize++;

	while(i != 0 && heapArr[parent(i)].damage < heapArr[i].damage){ //while we havent reached the root and the parents damage is larger than the current index damage
		swap(&heapArr[i], &heapArr[parent(i)]);
		i = parent(i);
	}
}

/*
Prints the elements in the heap
*/
void PriorityQ::print()
{
	for(int i = 0; i < currentSize; i++){
		cout << "\t" << "Item: " << heapArr[i].itemName << endl;
		cout << "\t" << "Damage: " << heapArr[i].damage << endl;
		cout << "\t" << "Comment: " << heapArr[i].comment << endl;
		cout << "\t" <<" =================" << endl;
	}
}


// Method to remove minimum element (or root) from min heap
void PriorityQ::pop()
{
	if(currentSize <= 0){
		cout << "PQ emptied..." << endl;
		return; //PQ empty
	}

	heapArr[0] = heapArr[currentSize - 1];
	currentSize--;
	heapify(0);
}


void PriorityQ::deleteKey(string item){
	int index = -1;
	for(int i = 0; i < currentSize; i++){
		if(heapArr[i].itemName == item){ //search heaparr for desired item
			index = i;
			break;
		}
	}
	if(index < 0) return; //Item not in PQ
	
	heapArr[index] = heapArr[currentSize - 1];
	currentSize--;

	if(index == currentSize) return; //we removed the last element so return

	int p = parent(index);
	if(index > 0 && heapArr[index].damage > heapArr[p].damage){ //Parent is larger then child so we need to bubble up
		while(index != 0 && heapArr[parent(index)].damage < heapArr[index].damage){ //while we havent reached the root and the parents damage is larger than the current index
			swap(&heapArr[index], &heapArr[parent(index)]); //swap parent and child
			index = parent(index);
		}
	}
	else{
		heapify(index); //Parent is not larger then child so we need to bubble down or leave as is
	}
}
