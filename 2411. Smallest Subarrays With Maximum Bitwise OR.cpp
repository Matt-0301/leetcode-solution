class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        std::vector<int> dp(32, 0);
        std::vector<int> res(nums.size(), 1);

        for(int i = nums.size()-1; i >= 0; i--){
            for(int bit = 0; bit < 32; bit++){
                if((nums[i] & (1 << bit)) > 0){
                    dp[bit] = i;
                }
                res[i] = std::max(res[i], dp[bit]-i+1);
            }
        }

        return res;
    }
};
