class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, profit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            profit += prices[i+1] - prices[i];
            if(profit > max_profit) max_profit = profit;
            if(profit < 0)  profit = 0;
        }

        return max_profit;
    }
};
