class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> tmp;
        DFS(result, nums, tmp, 0);

        return result;
    }

    void DFS(vector<vector<int>>& result, vector<int>& nums, vector<int>& tmp, int i){
        if(i == nums.size()){
            result.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        DFS(result, nums, tmp, i+1);

        tmp.pop_back();
        DFS(result, nums, tmp, i+1);
    }
};
