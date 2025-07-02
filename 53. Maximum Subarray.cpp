class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, tmp = 0;
        for(const auto& num: nums){
            tmp += num;
            if(tmp > res){
                res = tmp;
            }
            if(tmp < 0){
                tmp = 0;
            }
        }

        return res;

    }
};
