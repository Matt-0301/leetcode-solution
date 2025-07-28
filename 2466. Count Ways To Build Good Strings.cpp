class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        std::vector<int> dp(high+1, 0);
        dp[zero] += 1, dp[one] += 1;
        for(int i = 0; i <= high; i++){
            if(i - zero >= 0){
                dp[i] += dp[i-zero];
                dp[i] = dp[i] % 1000000007;
            }
            if(i - one >= 0){
                dp[i] += dp[i-one];
                dp[i] = dp[i] % 1000000007;
            }
        }
        // for(const auto& d: dp){
        //     cout << d << ", ";
        // }
        int res = 0;
        for(int i = low; i <= high; i++){
            res += dp[i];
            res = res % 1000000007;
        }
        return res;
    }
};
