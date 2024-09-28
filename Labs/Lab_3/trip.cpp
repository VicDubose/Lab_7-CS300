#include "trip.h"
#include <numeric>
#include <algorithm>

float moneyEqualizer(std::vector<float> expenses) {
    if (expenses.empty()) return 0.0f;

    // Calculate total expenses and average
    float total = std::accumulate(expenses.begin(), expenses.end(), 0.0f);
    float average = total / expenses.size();
    
    float amountToExchange = 0.0f;
    for (const auto& expense : expenses) {
        if (expense > average) {
            amountToExchange += (expense - average);
        }
    }

    return amountToExchange;
}
