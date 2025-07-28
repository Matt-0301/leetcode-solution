class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        std::vector<vector<int>> memo(nums.size(), vector<int>(sum*2+1, INT_MIN));

        return  backtracking(nums, target, 0, 0, memo, sum);
    }

    int backtracking(vector<int>& nums, int target, int index, int curSum, vector<vector<int>>& memo, int sum){     
        if(index == nums.size()){
            if(curSum == target)    return 1;
            else    return 0;
        }
        if(memo[index][curSum+sum] != INT_MIN){
            return memo[index][curSum+sum];
        }

        int res =  backtracking(nums, target, index+1, curSum+nums[index], memo, sum) + \
                backtracking(nums, target, index+1, curSum-nums[index], memo, sum);
        memo[index][curSum+sum] = res;

        return res;
    }
};
