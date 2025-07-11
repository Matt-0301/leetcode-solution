class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return std::max(nums[0], nums[1]);
        std::vector<int> dp(nums.size(), 0);
        int result;
        dp[0] = 0, dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            dp[i] = dp[i-2] + nums[i] > dp[i-1] ? dp[i-2] + nums[i] : dp[i-1];
        }

        dp[0] = nums[0], dp[1] = nums[0];
        for(int i = 2; i < nums.size()-1; i++){
            dp[i] = dp[i-2] + nums[i] > dp[i-1] ? dp[i-2] + nums[i] : dp[i-1];
        }

        return std::max(dp[nums.size()-2], dp[nums.size()-1]);
    }
};
