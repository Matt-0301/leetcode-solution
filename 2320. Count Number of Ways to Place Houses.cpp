class Solution {
private: 
    const int MOD = 1e9+7;
public:
    int countHousePlacements(int n) {
        if(n == 1)  return 4;
        std::vector<uint64_t> dp(n+1, 0);
        dp[0] = 1, dp[1] = 2;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }

        return (dp[n] * dp[n]) % MOD;
    }
};
