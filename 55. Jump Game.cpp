class Solution {
public:
    bool canJump(vector<int>& nums) {
        int final = nums[0];
        for(int i = 0; i < nums.size()-1; i++){
            if(final < i)   return false;
            if(final < i + nums[i]){
                final = i + nums[i];
            }
        }
        if(final >= nums.size()-1)   return true;
        return false;
    }
};
