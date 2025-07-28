class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        for(const auto num: nums){
            max = max | num;
        }

        return backtrack(nums, max, 0, 0);
    }

    int backtrack(vector<int>& nums, int max, int index, int bitOR){
        if(index == nums.size()){
            return (bitOR == max) ? 1 : 0;
        }
        if(bitOR == max){
            return pow(2, nums.size() - index);
        }
        return backtrack(nums, max, index+1, bitOR) + backtrack(nums, max, index+1, bitOR|nums[index]);
    }
};
