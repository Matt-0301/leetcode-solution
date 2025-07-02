class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // std::vector<int> result;
        // int prefix_sum = 1, len = nums.size();
        // for(int i = 0; i < len-1; i++){
        //     prefix_sum *= nums[i];
        //     result.push_back(prefix_sum);
        // }
        // result.push_back(prefix_sum);
        // prefix_sum = nums[len-1];
        // for(int i = len-2; i >= 1; i--){
        //     result[i] = result[i-1] * prefix_sum;
        //     prefix_sum *= nums[i];
        // }
        // result[0] = prefix_sum;

        // return result;
        int prefix_sum = 1, len = nums.size();
        std::vector<int> result(len, 1);
        for(int i = 0; i < len-1; i++){
            prefix_sum *= nums[i];
            result[i] = prefix_sum;
        }
        result[len-1] = prefix_sum;
        prefix_sum = nums[len-1];
        for(int i = len-2; i >= 1; i--){
            result[i] = result[i-1] * prefix_sum;
            prefix_sum *= nums[i];
        }
        result[0] = prefix_sum;

        return result;
    }
};
