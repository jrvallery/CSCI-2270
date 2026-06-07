#include "array_double.hpp"
#include <sstream>

/**
 * Reads the input file line by line, takes in the
 * query params along with reference of the passengers array
 */
void parseFile(ifstream& input, string queryParams[], AirlinePassenger *&passengers, int &arrCapacity, int &recordIdx, int &doublingCounter) {
    //TODO
    string line;
    while(getline(input, line)){
        stringstream ss(line);
        AirlinePassenger tempPassenger;
        string age;
        getline(ss, tempPassenger.name, ',');
        getline(ss, tempPassenger.airline, ',');
        getline(ss, tempPassenger.location, ',');
        getline(ss, age, ',');
        tempPassenger.age = stoi(age);

        // cout << "NAME: " << tempPassenger.name << endl;
        // cout << "LOCATION: " << tempPassenger.location << endl;
        // cout << "AIRLINE: " << tempPassenger.airline << endl;
        // cout << "AGE: " << tempPassenger.age << endl;
        
        int startAge = stoi(queryParams[2]);
        int endAge = stoi(queryParams[3]);
        if(isPassengerQueried(tempPassenger, queryParams[0], queryParams[1], startAge, endAge)){
            addPassenger(passengers, tempPassenger, arrCapacity, recordIdx, doublingCounter);
        }
    }
}

/**
 * Checks if the current passenger has their age in 
 * the queried age range, and their location and 
 * the airline matching with the queried ones.
 */
bool isPassengerQueried(AirlinePassenger passenger, string queryLocation, string queryAirline, int startAge, int endAge) {
    //TODO
    if((passenger.location == queryLocation) && (passenger.airline == queryAirline) && ((passenger.age >= startAge) && (passenger.age <= endAge))){
        return true;
    }
    return false;
}

/**
 * Takes in a reference to an array of structs (passengers) 
 * and the current arrayCapacity. It doubles the size 
 * of the array by making a new array of size the current
 * size and copying the elements of the old one. 
 */
void resizeArr(AirlinePassenger *&passengers, int *arraySize) {
   //TODO
   *arraySize *= 2;
    AirlinePassenger *tempPassengers = new AirlinePassenger[*arraySize];
    for(int i = 0; i < *arraySize / 2; i++){
        tempPassengers[i] = passengers[i];
    }
    delete[] passengers;
    passengers = tempPassengers;
}

/**
 * Append the new record to the passengers array. Here we double the 
 * array capacity whenever it is full. Assuming that the passenger to
 * be added is already checked if it satisfies the query params.
 */
void addPassenger(AirlinePassenger *&passengers, AirlinePassenger airlinePassenger, int &arrCapacity, int &recordIdx, int &doublingCounter) {
   //TODO
    if(recordIdx >= arrCapacity){
        resizeArr(passengers, &arrCapacity);
        doublingCounter++;
    }
    passengers[recordIdx] = airlinePassenger;
    recordIdx++;
}

string toLowerCase(string str){
    for (char& c : str) {
        c = std::tolower(c);
    }
    return str;
}
/**
 * Sorting the array of structs in descending order of age.
 * Tie breaker: Alphabetical order of names.
 */
void sortPassengers(AirlinePassenger *passengers, int length) {
    //TODO
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < length - i - 1; ++j){
            if((passengers[j].age < passengers[j + 1].age) || ((passengers[j].age == passengers[j + 1].age)
                                                           && (toLowerCase(passengers[j].name) > toLowerCase(passengers[j + 1].name)))){
                // Swap elements
                AirlinePassenger temp = passengers[j];
                passengers[j] = passengers[j + 1];
                passengers[j + 1] = temp;
            }
        }
    }
}


/**
 * Call the sortPassenger function and print the name and the age of the passenger.
 */
void printQueriedPassengers(AirlinePassenger *passengers, int numOfRecords) {
    //TODO
    sortPassengers(passengers, numOfRecords);
    cout << "Queried Passengers\n---------------------------------------" << endl;
    for(int i = 0; i < numOfRecords; i++){
        cout << passengers[i].name << " " << passengers[i].age << endl;
    }
}
