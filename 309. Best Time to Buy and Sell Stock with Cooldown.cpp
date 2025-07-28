class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<vector<int>> memo(prices.size(), vector<int>(2, INT_MIN));
        return backtrack(prices, 0, false, memo);
    }

    int backtrack(vector<int>& prices, int index, bool hasBuy, vector<vector<int>>& memo){
        if(index >= prices.size()){
            return 0;
        }
        if(memo[index][hasBuy] != INT_MIN){
            return memo[index][hasBuy];
        }

        int profit;
        if(hasBuy){
            profit = std::max(prices[index] + backtrack(prices, index+2, !hasBuy, memo), \
                                backtrack(prices, index+1, hasBuy, memo));
            memo[index][1] = profit;
        }else{
            profit = std::max(backtrack(prices, index+1, !hasBuy, memo) - prices[index], \
                            backtrack(prices, index+1, hasBuy, memo));
            memo[index][0] = profit;
        }

        return profit;
    }
};
