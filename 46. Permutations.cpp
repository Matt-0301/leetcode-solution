class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> subset;
        backtracking(nums, result, subset, 0);

        return result;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset,int index){
        if(index == nums.size()){
            result.push_back(subset);
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums, i, index);
            subset.push_back(nums[index]);
            backtracking(nums, result, subset, index+1);
            swap(nums, i, index);
            subset.pop_back();
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
