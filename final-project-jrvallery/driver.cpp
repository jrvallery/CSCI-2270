#include<iostream>
#include <vector>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "hash.hpp"
#include "PriorityQueue.hpp"
#include "enemy_graph.hpp"

using namespace std;
using namespace std::chrono;

#include <sstream>
#include <string>
using namespace std;

bool isInteger(string& s) {
    stringstream ss(s);
    int x;
    char c;
    if (!(ss >> x)) return false;
    if (ss >> c) return false;
    return true;
}


void displayMenu()//keep it in starter code
{
    cout<<"------------------"<<endl;
    cout<<"1: Build the datastructure (call it only once)"<<endl;
    cout<<"2: Add a new item"<<endl;
    cout<<"3: Peek most powerful item from character"<<endl;
    cout<<"4: Pop most powerful item from character"<<endl;
    cout<<"5: Print all items for character"<<endl;
    cout<<"6: Get number of collisions"<<endl;
    cout<<"7: Print the table"<<endl;
	cout<<"8: Find easiest route through dungeon"<<endl;
    cout<<"9: Exit"<<endl;
    cout<<"------------------"<<endl;

}

int main(int argc, char* argv[])
{
    if (argc <3)
    {
        cout<<"need correct num of arg"<<endl;
    }
    string fname =argv[1];
    int tableSize = stoi(argv[2]);
    
    int ch = 0;
    string chs;
    HashTable ht(5);
    bool built = false;
    while(ch!=9)
    {
        displayMenu();
        cout<<"Give your choice >> ";
        getline(cin, chs);
        if(!isInteger(chs)){
            cout << "Enter a valid integer" << endl;
            continue;
        }
        int c = stoi(chs);
        
        ch =stoi(chs);
        switch (ch)
        {
            case 1:{ // bulk build (should only build on first call)
				// TODO
                if(built == true){
                    cout << "already built" << endl;
                    break;
                }
                ht.buildBulk(fname);
                built = true;

                break;
            }
            case 2:{ // Insert new items from console
				// TODO
                string characterName, itemName, comment;
                string damage;

                cout << "Chacter Name: ";
                getline(cin, characterName);

                cout << "Item Name: ";
                getline(cin, itemName);

                cout << "Damage (int): ";
                getline(cin, damage);
                if(!isInteger(damage)){
                    cout << "Enter a valid integer" << endl;
                    break;
                }

                cout << "Comment: ";
                getline(cin, comment);

                ItemInfo item = {characterName, itemName, stoi(damage), comment};
                ht.insertItem(item);

                break;
            }
            case 3:{ // Peek 
				//TODO
                string characteName;
                cout << "Chacter Name: ";
                getline(cin, characteName);
                node* c = ht.searchCharacter(characteName);
                if(!c){
                    cout << "no record found." << endl;
                    break;
                }

                ItemInfo* item = c->pq.peek();
                cout << "Chacter Name: " << item->characterName << endl;
                cout << "Item Name: " << item->itemName << endl;
                cout << "Damage : " << item->damage << endl;
                cout << "Comment: " << item->comment << endl;

                break;
			}
            case 4:{ // Pop
				// TODO
                string characterName;
                cout << "Character Name: ";
                getline(cin, characterName);
                node* c = ht.searchCharacter(characterName);
                c->pq.pop();

                break;
            }
            case 5:{ // Print all items for character
				// TODO
                string characterName;
                cout << "Character Name: ";
                getline(cin, characterName);
                node* c = ht.searchCharacter(characterName);
                c->pq.print();

                break;
			}
            case 6: { // Display collisions
				// TODO
                cout << "Number of collision: " << ht.getNumCollision() << endl;

                break;
			}
            case 7: { // Print table
				// TODO
                ht.printTable();

                break;
			}
			case 8:{ // Find easiest path through dungeon
				cout << "Input dungeon(file name): " << endl;
				string dungeonFile;
				getline(cin, dungeonFile);
				EnemyGraph G;
				if(!G.buildGraphFromFile(dungeonFile)){
                    break;
                }
				cout << G.findEasiestPath(ht) << endl;
                
				break;
			}
			case 9:
				cout << "Goodbye..." << endl;
				break;
       
            default:
                cout<<"Give a valid entry"<<endl;
                break;
        }
    }
}
