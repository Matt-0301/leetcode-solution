class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int len = nums.size();
        int mustpick, left, right, target;
        for(mustpick = 0; mustpick <= len-3; mustpick++){
            if(mustpick > 0 && nums[mustpick] == nums[mustpick-1])  continue;
            target = -nums[mustpick];
            left = mustpick + 1;
            right = len - 1;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    result.push_back({nums[mustpick], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]){
                        ++left;
                    }
                    while(left < right && nums[right] == nums[right-1]){
                        --right;
                    }
                    ++left;
                    --right;
                }else if(nums[left] + nums[right] < target){
                    ++left;
                }else{
                    --right;
                }
            }
        }
        return result;
    }
};
