#ifndef HASH_HPP
#define HASH_HPP

#include <string>
#include "PriorityQueue.hpp"
#include <fstream>

using namespace std;

struct node
{
	string characterName;
    PriorityQ pq;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    /*
    -table is a dynamically allocated array of pointers.
    -Each table[i] is a pointer to the head node of a linked list.
    -Each node points to the next via a next pointer.
    */
    node** table;
    
    node* createNode(string charName, node* next);
    
    int numCollision;
public:
    HashTable(int bsize);  // Constructor
    ~HashTable(); // Destructor
    
    void buildBulk(string fname);
    
    void insertItem(ItemInfo item);

    
    unsigned int hashFunction(string key);

    int getNumCollision(){return numCollision;};
    

    node* searchCharacter(string character);
    
    void printTable();

	void deleteEntry(string characterName, string itemName);
};

#endif
