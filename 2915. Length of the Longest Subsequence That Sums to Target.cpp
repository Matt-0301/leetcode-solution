// // Method1: DP(top-down + memoization)
// class Solution {
// public:
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n = nums.size();
//         std::vector<vector<int>> memo(n, vector<int>(target+1, -1));
//         int res = DFS(nums, n-1, target, memo);
//         return (res < 0) ? -1 : res;
//     }

//     int DFS(vector<int>& nums, int index, int cur, vector<vector<int>>& memo){
//         if(cur == 0){
//             return 0;
//         }
//         if(index < 0 || cur < 0){
//             return INT_MIN;
//         }

//         if(memo[index][cur] != -1){
//             return memo[index][cur];
//         }

//         return memo[index][cur] = std::max(DFS(nums, index-1, cur, memo), \
//                                     1+DFS(nums, index-1, cur-nums[index], memo));
//     }
// };

// Method2: DP(bottom-up)
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        std::vector<int> dp(target+1, -1);
        dp[0] = 0;
        for(const auto& num: nums){
            for(int i = target; i >= num; i--){
                if(dp[i-num] != -1){
                    dp[i] = std::max(dp[i-num]+1, dp[i]);
                }
            }
        }

        return dp[target];
    }
};
