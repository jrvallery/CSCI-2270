#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../code/array_double.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    //TODO

    string args[4];
    for(int i = 2; i <= 5; i++){
        args[i - 2] = argv[i];
    }
    ifstream inFile(argv[1]);
    if(!inFile){
        cout << "Failed to open: 'passengers.txt'" << endl;
        return -1;
    }
    int arrCapacity = 10;
    int recordIdx = 0;
    int doublingCounter = 0;

    AirlinePassenger *passengers = new AirlinePassenger[arrCapacity];
    parseFile(inFile, args, passengers, arrCapacity, recordIdx, doublingCounter);

    cout << "Array doubled: " << doublingCounter << endl;
    cout << "Total number of passengers returned after the query: " << recordIdx << endl;

    printQueriedPassengers(passengers, recordIdx);

    delete[] passengers;
    inFile.close();
    return 0;
}
