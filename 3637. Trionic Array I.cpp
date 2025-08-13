class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4 || nums[0] >= nums[1]){
            return false;
        }

        int p = -1, q = -1;
        for(int i = 1; i < n-1; i++){
            if(nums[i-1] == nums[i]){
                return false;
            }
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                if(p != -1){
                    return false;
                }
                p = i;
            }

            if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                if(q != -1){
                    return false;
                }
                q = i;
            }
        }
        if(nums[n-1] == nums[n-2]){
            return false;
        }
        if(p == -1 || q == -1 || p > q){
            return false;
        }
        return true;
    }
};
