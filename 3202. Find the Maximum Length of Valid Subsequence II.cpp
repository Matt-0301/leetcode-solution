class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        std::vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for(const auto& num: nums){
            int n = num % k;
            for(int i = 0; i < k; i++){
                dp[i][n] = dp[n][i] + 1;

                res = (dp[i][n] > res) ? dp[i][n] : res;
            }
        }

        return res;
    }
};
