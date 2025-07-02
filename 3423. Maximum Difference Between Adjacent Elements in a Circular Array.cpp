class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int len = nums.size(), diff = abs(nums[0] - nums[len-1]);
        for(int i = 0; i < len-1; i++){
            if(diff < abs(nums[i] - nums[i + 1])){
                diff = abs(nums[i] - nums[i + 1]);
            }
        }

        return diff;
    }
};
