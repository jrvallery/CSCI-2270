#include "BookCollection.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Book* deleteBook(Book* r, string bookName);
Book* getSuccessor(Book* r);
Book* rotateLeft(Book* r, string bookName);
bool searchBook(Book* r, string bookName);
void deleteTree(Book* r);

using namespace std;

BookCollection::BookCollection() {
    //TODO
    root = nullptr;
}

BookCollection::~BookCollection() {
    //TODO
    deleteTree(root);
}


void BookCollection::removeBook(string bookName) {
    if (!searchBook(root, bookName)) {
        cout << "Book not found!" << endl;
    }
    root = deleteBook(root, bookName);
}


void BookCollection::rotateLeftCollection(string bookName) {
    //TODO
    root = rotateLeft(root, bookName);
}


string BookCollection::closestParent(string book1, string book2) {
    if (!searchBook(root, book1) || !searchBook(root, book2)) {
        cout << "Book not found!" << endl;
        return "Error - wrong book name";
    }

    Book* crawler = root;
    while (crawler) {
        if (crawler->bookName > book1 && crawler->bookName > book2) {
            crawler = crawler->left;
        } else if (crawler->bookName < book1 && crawler->bookName < book2) {
            crawler = crawler->right;
        } else {
            return crawler->bookName;
        }
    }
    return "";
}


Book* deleteBook(Book* r, string bookName){
    //Traverse to find book
    if (!r){
        return nullptr;
    }
    if (r->bookName > bookName){
        r->left = deleteBook(r->left, bookName);
    }
    else if (r->bookName < bookName){
        r->right = deleteBook(r->right, bookName);
    }
    //Booknames match
    else{
        //root has only right child or no child
        if(r->left == nullptr){
            Book* temp = r->right;
            delete r;
            return temp;
        }
        //root has only left child or no child
        if(r->right == nullptr){
            Book* temp = r->left;
            delete r;
            return temp;
        }
        //Delete node with two children
        Book* successor = getSuccessor(r);
        r->bookName = successor->bookName;
        r->author = successor->author;
        r->rating = successor->rating;
        r->right = deleteBook(r->right, successor->bookName);
    }
    return r;
}


Book* getSuccessor(Book* r){
    Book* temp = r->right;
    while (temp && temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}


Book* rotateLeft(Book* r, string bookName) {
    if (!r) return nullptr;
    
    if (r->bookName == bookName) {
        // Found the node to rotate
        if (!r->right) return r; // No right child, can't rotate
        
        Book* newRoot = r->right;
        r->right = newRoot->left;
        newRoot->left = r;
        return newRoot;
    }
    else if (r->bookName < bookName) {
        r->right = rotateLeft(r->right, bookName);
    }
    else {
        r->left = rotateLeft(r->left, bookName);
    }
    return r;
}


bool searchBook(Book* r, string bookName) {
    if (!r) return false;
    if (r->bookName == bookName) return true;
    if (bookName < r->bookName) return searchBook(r->left, bookName);
    else return searchBook(r->right, bookName);
}


void deleteTree(Book* r){
    if (!r) return;
    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
    r = nullptr;
}
 