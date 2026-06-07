#include <iostream>

using namespace std;


void doubleArr(int* &arr, int &arrSize){
    arrSize *= 2;
    int* newArr = new int[arrSize];
    
    for(int i = 0; i < arrSize / 2; i++){
        newArr[i] = arr[i];
    }
    for(int i = arrSize / 2; i < arrSize; i++){
        newArr[i] = 0; 
    }

    delete[] arr;
    arr = newArr;
}

void printArr(int arr[], int arrSize, int numElements){
    for(int i = 0; i < numElements; i++){
        if((i % 10 == 0) && (i != 0)){cout << endl;}
        if((i % 100 == 0) && (i != 0)){cout << endl;}
        if((i % 1000 == 0) && (i != 0)){cout << endl;}
        if((i % 10000 == 0) && (i != 0)){cout << endl;}

        cout << arr[i] << " ";
    }
}

int main(){
    int arrSize = 2;
    int* arr = new int[arrSize];
    int numElements = 10000;
    int timesDouble = 0;
    
    for(int i = 0; i < numElements; i++){
        if(i >= arrSize){
            doubleArr(arr, arrSize);
            timesDouble++;
        }
        arr[i] = i;
    }
    cout << "Times Doubled: " << timesDouble << endl;
    printArr(arr, arrSize, numElements);
    delete[] arr;
}