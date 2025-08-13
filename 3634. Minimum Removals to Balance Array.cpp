class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for(int left = 0; left < n; left++){
            long long val = 1LL*nums[left]*k;
            int index = BS(nums, left, n-1, val);
            // cout << index << endl;
            res = std::min(res, left+(n-index));
        }

        return res;
    }

    int BS(vector<int>& nums, int left, int right, long long val){
        int mid = (left+right)/2;
        while(left <= right){
            if(1LL*nums[mid] <= val){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
            mid = (left+right)/2;
        }

        return left;
    }
};
