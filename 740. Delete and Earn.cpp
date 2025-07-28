class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        std::vector<int> dp(max+1, 0);
        for(const auto& num: nums){
            ++dp[num];
        }

        for(int i = 2; i <= max; i++){
            dp[i] = dp[i] * i;
            dp[i] = std::max(dp[i] + dp[i-2], dp[i-1]);
        }

        return dp[max];
    }
};
