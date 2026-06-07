#include "BookCollection.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void traverseTree(Book* r);
void findAuthors(Book* r, string author);
void findHighRate(Book* r, double &highRate);
void findHighRates(Book* r, double &highRate);
void deleteBooks(Book* r);
int getHeight(Book *r);


BookCollection::BookCollection() {
    //TODO
    this->root = nullptr;
}


BookCollection::~BookCollection() {
    //TODO
    deleteBooks(this->root);
}


void BookCollection::addBook(string bookName, string author, double rating) {
    //TODO
    Book* newB = new Book(bookName, author, rating);
    Book* crawler = root;
    if(crawler == nullptr){
        root = newB;
        return;
    }
    while(crawler != nullptr){
        if(newB->bookName > crawler->bookName){
            if (crawler->right == nullptr){
                crawler->right = newB;
                return;
            }
            crawler = crawler->right;
        }
        else{
            if (crawler->left == nullptr){
                crawler->left = newB;
                return;
            }
            crawler = crawler->left;
        }
    }
}


void BookCollection::showBookCollection() {
    //TODO
    if(!root){
        cout << "Collection is empty." << endl;
        return;
    }
    traverseTree(root);
}


void BookCollection::showBook(string bookName) {
    //TODO
    Book* crawler = root;
    while(crawler != nullptr && crawler->bookName != bookName){
        if(crawler->bookName < bookName){
            crawler = crawler->right;
        }
        else{
            crawler = crawler->left;
        }
    }
    if(crawler == nullptr){
        cout << "Book not found." << endl;
        return;
    }
    cout << "Book:" << endl;
    cout << "==================" << endl;
    cout << "Name :" << crawler->bookName << endl;
    cout << "Author :" << crawler->author << endl;
    cout << "Rating :" << crawler->rating << endl;
}


void BookCollection::showBooksByAuthor(string author) {
    //TODO
    cout << "Books By: " << author << endl;
    findAuthors(root, author);
}



void BookCollection::showHighestRatedBooks() {
    //TODO
    if(root == nullptr){
        cout << "Collection is empty." << endl;
        return;
    }
    double highRate = 0;
    findHighRate(root, highRate);
    cout << "Highest Rating: " << highRate << endl;
    findHighRates(root, highRate);
    return;
}


int BookCollection::getHeightOfBookCollection() {
    //TODO
    return getHeight(root);
}


void traverseTree(Book* r){
    //Base 
    if(!r){
        return;
    }
    //Left
    traverseTree(r->left);
    //root
    cout << "BOOK: " << r->bookName << " BY: " << r->author << " RATING: " << r->rating << endl;
    //right
    traverseTree(r->right);
    //return
    return;
}


void findAuthors(Book* r, string author){
    if(!r){
        return;
    }
    findAuthors(r->left, author);
    if(r->author == author){
        cout << r->bookName << " RATING: " << r->rating << endl;
    }
    findAuthors(r->right, author);
}


void findHighRate(Book* r, double &highRate){
    if(!r){
        return;
    }
    findHighRate(r->left, highRate);
    if(highRate < r->rating){
        highRate = r->rating;
    }
    findHighRate(r->right, highRate);
}


void findHighRates(Book* r, double &highRate){
    if(!r){
        return;
    }
    findHighRates(r->left, highRate);
    if(highRate == r->rating){
        cout << r->bookName << " BY: " << r->author << endl;
    }
    findHighRates(r->right, highRate);
    return;
}


void deleteBooks(Book* r){
    if(!r){
        return;
    }
    deleteBooks(r->left);
    deleteBooks(r->right);
    delete r;
}


int getHeight(Book *r){
    if (!r) return 0; // If height is measured in edges, return -1
    return 1 + max(getHeight(r->left), getHeight(r->right));
}