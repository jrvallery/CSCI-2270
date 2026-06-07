#include "fundamentals.hpp"

void insertStockInfo(stockInfo stocks[], string company_name, double stock_prices_arr[], int index) {
    stockInfo stock;
    stock.company_name = company_name;
    double total = 0.0;
    for(int i = 0; i < 5; i++){
        stock.stock_prices_arr[i] = stock_prices_arr[i];
        total += stock_prices_arr[i]; 
    }
    stock.average = total / 5.0;
    stocks[index] = stock;
}

void displaySortedStocks(stockInfo stock, ofstream& file){
    // TODO

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            if (stock.stock_prices_arr[j] > stock.stock_prices_arr[j + 1]) {
                // Swap elements
                double temp = stock.stock_prices_arr[j];
                stock.stock_prices_arr[j] = stock.stock_prices_arr[j + 1];
                stock.stock_prices_arr[j + 1] = temp;
            }
        }
    }
    file << stock.company_name << "," << stock.average << ",";
    cout << stock.company_name << "," << stock.average << ",";
    for(int i = 0; i < 5; i++){
        if(i == 4){
            file << stock.stock_prices_arr[i];
            cout << stock.stock_prices_arr[i];
            break;
        }
        file << stock.stock_prices_arr[i] << ",";
        cout << stock.stock_prices_arr[i] << ",";
    }
    cout << endl;
    file << endl;
    return;
}