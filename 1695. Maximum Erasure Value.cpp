class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        std::unordered_set<int> set;
        int left = 0, right= 0, res = 0, cur_total = 0;
        while(right < nums.size()){
            if(set.count(nums[right])){
                while(nums[left] != nums[right]){
                    set.erase(nums[left]);
                    cur_total -= nums[left];
                    ++left;
                }
                ++left;
            }else{
                set.insert(nums[right]);
                cur_total += nums[right];
            }
            res = (cur_total > res) ? cur_total : res;
            ++right;
        }

        return res;
    }
};
