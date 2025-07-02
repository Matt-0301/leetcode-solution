class Solution {
public:
    int findMin(vector<int>& nums) {
        int r_left = 0, r_right = nums.size()-1, r_mid = (r_left+r_right)/2;
        while(r_left <= r_right){
            // cout << r_left << ", " << r_right << ", " << r_mid  << ", " << nums[r_mid] << endl;
            if((r_mid == 0 || nums[r_mid] < nums[r_mid -1]) && \
                (r_mid == nums.size()-1 || nums[r_mid] < nums[r_mid + 1])){
                return nums[r_mid];
            }else if(nums[r_mid] >= nums[r_left] && nums[r_mid] > nums[r_right]){
                r_left = r_mid + 1;
            }else{
                r_right = r_mid - 1;
            }

            r_mid = (r_left + r_right) / 2;
        }

        return nums[r_mid];
    }
};
