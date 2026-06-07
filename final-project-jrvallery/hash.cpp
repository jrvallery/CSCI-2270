// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"
#include<sstream>


using namespace std;


node* HashTable::createNode(string charName, node* nextNode)
{
	// TODO
	node* n = new node;
	n->characterName = charName;
	n->next = nextNode;

	return n;
}


HashTable::HashTable(int bsize)
{
	// TODO
	tableSize = bsize;
	numCollision = 0;
	table = new node*[tableSize];
	for(int i = 0; i < bsize; i++){
		table[i] = nullptr;
	}
}


void HashTable::printTable()
{
	// TODO
	for(int i = 0; i < tableSize; i++){
		cout << "table[" << i << "]: ";

		node* head = table[i];
		bool first = true;

		while(head){
			if(!first) cout << ", ";
			cout << head->characterName;
			head = head->next;
			first = false;
		}
		cout << endl;
	}
}


//function to calculate hash function
unsigned int HashTable::hashFunction(string charName)
{
	// TODO
	//Calculates sum of all the ASCII values in charName
	int sum = 0;
	for(int i = 0; i < charName.size(); i++){
		sum += int(charName[i]);
	}

	return (sum % tableSize);
}



node* HashTable::searchCharacter(string charName)
{
	// TODO
	int index = hashFunction(charName);
	//grabs head of LL from corresponding hash bucket
	node* head = table[index];
	while (head)
	{
		if(head->characterName == charName){
			return head;
		}
		head = head->next;
	}
	return nullptr;
}



//function to insert
void HashTable::insertItem(ItemInfo newItem)
{
	// TODO
	string charName = newItem.characterName;
	node* character = searchCharacter(charName);

	// if(character){
	// 	cout << character->pq.peek()->characterName << "; ";
	// 	cout << "True" << endl;
	// }
	// else{
	// 	cout << "False" << endl;
	// }

	//checks if character already exsists and adds item to pq
	if(character){
		character->pq.insertElement(newItem);
		return;
	}

	//The character dosent exsist in hash bucket
	int index = hashFunction(charName);
	
	//Here we are doing O(1) head insertion as we set n->next to the original head
	node* n = createNode(newItem.characterName, table[index]); //New charcter node
	n->pq.insertElement(newItem);

	//if there was already a node at the head we increase the number of collisons and swap the head with our new node
	if(table[index] != nullptr){
		numCollision++;
	}
	table[index] = n; //Set new node to the head of given bucket
}


//Split function to seperate out key values
int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    if(input_string == ""){
        return 0;
    }
    int count = 0;
    int start = 0;
    int length = input_string.length();
    for(int i = 0; i <= length; i++){
        if (i == length || input_string[i] == separator) {
            if (count >= ARR_SIZE) {
                return -1;
            }
            arr[count] = input_string.substr(start, i - start);  // Store substring.
            count++;
            start = i + 1;
        }
    }
    return count;
}


//Go line by line through passed filename, create a new item with retreived info. (builds hashtable in bulk with passed filename)
void HashTable:: buildBulk(string fname) {
    // TODO
	string line;
	ifstream inFile(fname);
    
    if (inFile.fail()) {
        return;
    }
	while(getline(inFile, line)){
		string arr[4];
		split(line, ';', arr, 4);
		int damage = stoi(arr[2]);
		ItemInfo item = {arr[0], arr[1], damage, arr[3]};
		insertItem(item);
	}
}


//Delete a specific item from priority queue
void HashTable::deleteEntry(string charName, string itemName) {
	// TODO
	int index = hashFunction(charName);
	node* head = table[index];
	node* prev = nullptr; //Stores previous to head to maintain all memory
	while(head){
		if(head->characterName == charName){
			break;
		}
		prev = head;
		head = head->next;
	}
	if(!head){
		cout << "no record found" << endl;
		return;
	}
	head->pq.deleteKey(itemName);

	if(head->pq.isEmpty()){ //Delete Character if PQ emptied with deletion
	
		if(prev){ //node is not first in chain
			prev->next = head->next;
		}

    	else{ //node is the head
			table[index] = head->next;
		}
		delete head;
	}
}


HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; ++i) //Iterates through every bucket in the table
    {
        node* current = table[i]; 
        while (current != nullptr) //crawls along linked list deleting every node
        {
            node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table; //Finally it deletes itself freeing all memory
}