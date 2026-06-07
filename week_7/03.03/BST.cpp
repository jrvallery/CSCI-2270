#include <iostream>

using namespace std;

struct Node
{
    int d;
    Node *left, *right;
};


Node* newNode(int data){
    Node* n = new Node;
    n->d = data;
    //New nodes inserted are always leaves
    n->left = nullptr;
    n->right = nullptr;
    return n;
}


void inOrder(Node *r){
    //Base Case
    if(r == nullptr){
        return; //Way back up the tree
    }
    // Print all values < r->data
    inOrder(r->left);
    // Print r->data
    cout << r->d << endl;
    // Print all values > r->data
    inOrder(r->right); 
}


void preOrder(Node *r){
    //Base Case
    if(r == nullptr){
        return; //Way back up the tree
    }
    // Print r->data
    cout << r->d << endl;
    // Print all values < r->data
    preOrder(r->left);
    // Print all values > r->data
    preOrder(r->right); 
}


Node* insertNode(Node *r, int data){
    //Base Case
    if(r == nullptr){
        return newNode(data);
    }

    if (data < r->d) {
        r->left = insertNode(r->left, data);
    }
    else {
        r->right = insertNode(r->right, data);
    }
    return nullptr;
}


int main(){
    Node *root = insertNode(nullptr, 10);
    root = insertNode(root, 5);


    inOrder(root);
    return 0;
}
