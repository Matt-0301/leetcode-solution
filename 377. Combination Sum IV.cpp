class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(const auto& num: nums){
                if(num <= i){
                    dp[i] += dp[i-num];
                }
            }
        }

        return dp[target];
    }
};
