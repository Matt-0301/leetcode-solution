class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allOdd = 0, allEven = 0, oddEven = 1;
        if(nums[0] % 2 == 0)    ++allEven;
        else    ++allOdd;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] % 2 == 0)    ++allEven;
            else    ++allOdd;

            if(nums[i] % 2 != nums[i-1] % 2)    ++oddEven;
        }

        return std::max({allOdd, allEven, oddEven});
    }
};
