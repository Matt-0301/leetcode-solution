class Solution {
public:
    int maxSum(vector<int>& nums) {
        std::unordered_set<int> set;
        int res = 0;
        for(const auto& num: nums){
            if(num > 0 && !set.count(num)){
                set.insert(num);
                res += num;
            }
        }

        return (res == 0) ? *max_element(nums.begin(), nums.end()) : res;
    }
};
