#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto max_profit = 0;
        vector<int> profit(prices.size(), 0);

        for(auto i = 1; i < prices.size(); ++i) {
            auto diff_price = prices[i] - prices[i-1];
            if (diff_price + profit[i-1] < 0) profit[i] = 0;
            else profit[i] = diff_price + profit[i-1];

            if (profit[i] > max_profit) max_profit = profit[i];
        }

        return max_profit;
    }
};

int main() {
    return 0;
}
