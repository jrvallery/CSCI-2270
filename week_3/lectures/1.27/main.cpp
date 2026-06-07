#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int* aHP = new int;
    *aHP = 15;
    *aHP = a;

    delete aHP;
    aHP = nullptr;
    *aHP = 10;
    cout << *aHP << endl;
}