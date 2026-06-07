#include <iostream>
#include <fstream>
#include "../code/fundamentals.hpp"
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {
    // TODO
    ifstream inFile(argv[1]);
    // if (!inFile.is_open()) {
    //     cout << "Could not open the file." << endl;
    //     return 1;
    // }
    vector<vector<string>> stocksTemp;
    string line;

    while (getline(inFile, line))
    {
        vector<string> stock;
        string cell;
        stringstream ss(line);
        while(getline(ss, cell, ',')){
            stock.push_back(cell);
        }
        stocksTemp.push_back(stock);
    }

    inFile.close();
    int size = stocksTemp.size();
    stockInfo stocks[size];
    ofstream outFile(argv[2]);

    for(int i = 0; i < size; i++){
        double stockData[5];
        for(int j = 1; j < 6; j++){
            stockData[j - 1] = stod(stocksTemp[i][j]);
        }
        insertStockInfo(stocks, stocksTemp[i][0], stockData, i);
        displaySortedStocks(stocks[i], outFile);
    }

    return 0;
}

