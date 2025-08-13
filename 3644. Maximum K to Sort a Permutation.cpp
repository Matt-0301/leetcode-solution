class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]){
                res  = res & nums[i];
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};
