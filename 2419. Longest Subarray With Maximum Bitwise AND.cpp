class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 1, tmp = 1, max = *max_element(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == max && nums[i] == nums[i-1]){
                tmp++;
            }else{
                tmp = 1;
            }

            res = std::max(res, tmp);
        }

        return res;
    }
};
