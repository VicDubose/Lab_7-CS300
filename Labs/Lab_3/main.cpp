#include <iostream>
#include <vector>
#include <sstream>
#include "trip.h"
using namespace std;

int main() {
    string input;
    vector<float> expenses;
    cout << "Enter expenses separated by spaces: ";
    getline(cin, input);
    stringstream ss(input);
    float expense;
    while (ss >> expense) {
        expenses.push_back(expense);
    }

    cout  << moneyEqualizer(expenses) << endl;

    return 0;
}
