// // Method1: dynamic programming(top-down)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         std::vector<int> dp(nums.size(), 1);

//         for(int i = 1; i < nums.size(); i++){
//             for(int j = i-1; j >= 0; j--){
//                 if(nums[i] > nums[j]){
//                     dp[i] = std::max(dp[j] + 1, dp[i]);
//                 }
//             }
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };

// method2: binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }else{
                int index = binarySearch(dp, nums[i]);
                dp[index] = nums[i];
            }
        }

        return dp.size();
    }

    int binarySearch(vector<int>& arr, int val){
        int mid, left = 0, right = arr.size()-1;

        while(left <= right){
            mid = (left + right) / 2;
            if(arr[mid] == val){
                return mid;
            }else if(arr[mid] < val){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};
