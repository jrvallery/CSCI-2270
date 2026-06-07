#include <iostream>
using namespace std;


int func(int inputPointer[]){
    cout << "Types Matched!" << endl;

    *inputPointer = 42;

    return *inputPointer;
}


int replaceArray(int* &a){
    int b[6] = {4,5,6,7,8,9};
    a = b;
    return 0;
}


int main(){
    int x = 12;
    int *arrayPointer = &x;
    int array[3] = {1,2,3};

    cout << "func:\n\t" << func(array) << endl;

    replaceArray(arrayPointer);
    cout << "after func... first value: " << *arrayPointer << endl;
    return 0;
}