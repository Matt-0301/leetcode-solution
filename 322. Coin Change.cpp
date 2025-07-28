class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, -1);
        if(amount == 0) return 0;

        for(int i = 1; i <= amount; i++){
            for(const auto coin: coins){
                if(coin == i){
                    dp[i] = 1;
                }else if(coin < i){
                    if(dp[i-coin] != -1){
                        if(dp[i] == -1 || dp[i-coin]+1 < dp[i]){
                            dp[i] = dp[i-coin] + 1;
                        }
                    }
                }else{
                    continue;
                }
            }
        }

        // for(const auto& d: dp){
        //     cout << d << ", ";
        // }
        // cout << endl;
        return dp[amount];
    }
};
