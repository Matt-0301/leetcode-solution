class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> result;
        int interval_start = -1;
        for(int i = 0; i < nums.size(); i++){
            if(interval_start == -1){
                interval_start = i;
            }
            if(i == nums.size() - 1 || nums[i] + 1 != nums[i+1]){
                string tmp;
                if(i == interval_start){
                    tmp = to_string(nums[i]);
                }else{
                    tmp = to_string(nums[interval_start]) + "->" + to_string(nums[i]);
                }
                result.push_back(tmp);
                interval_start = -1;
            }
        }

        return result;
    }
};
