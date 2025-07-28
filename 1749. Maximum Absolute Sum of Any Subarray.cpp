class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_res = INT_MAX, max_res = INT_MIN, cur_min_res = 0, cur_max_res = 0;

        for(const auto& num: nums){
            cur_min_res += num;
            cur_max_res += num;

            cur_max_res = std::max(cur_max_res, 0);
            cur_min_res = std::min(cur_min_res, 0);

            max_res = std::max(max_res, cur_max_res);
            min_res = std::min(min_res, cur_min_res);
        }

        return std::max(abs(min_res), max_res);
    }
};
