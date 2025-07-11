// // Method1: Dynamic Programming
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         std::vector<int> dp(nums.size(), 10001);
//         dp[0] = 0;
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = 1; i+j < nums.size() && j <= nums[i]; j++){
//                 dp[i+j] = std::min(dp[i]+1, dp[i+j]);
//             }
//         }
//         return dp[nums.size()-1];
//     }
// };

// Method2: Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = nums[0], current_end = nums[0], result = 0;
        for(int i = 1; i < nums.size()-1; i++){
            farthest = std::max(farthest, i + nums[i]);
            if(i == current_end){
                ++result;
                current_end = farthest;
            }
        }
        // cout << current_end << endl;
        if(nums.size() != 1 && current_end >= nums.size()-1)  return ++result;
        return result;
    }
};
