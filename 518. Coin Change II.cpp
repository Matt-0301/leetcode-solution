class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::sort(coins.begin(), coins.end());
        std::vector<vector<int>> memo(amount+1, vector<int>(coins.size(), -1));

        return DFS(amount, coins, 0, memo);
    }

    int DFS(int amount, vector<int>& coins, int coinIndex, vector<vector<int>>& memo){
        if(amount == 0){
            return 1;
        }
        if(coinIndex >= coins.size()){
            return 0;
        }
        if(memo[amount][coinIndex] != -1){
            return memo[amount][coinIndex];
        }

        int res = 0;
        if(coins[coinIndex] <= amount){
            res = DFS(amount-coins[coinIndex], coins, coinIndex, memo);
            res += DFS(amount, coins, coinIndex+1, memo);
        }
        memo[amount][coinIndex] = res;

        return res;
    }
};
