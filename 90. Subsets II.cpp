// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         std::vector<vector<int>> result;
//         std::vector<int> subset;
//         std::sort(nums.begin(), nums.end());
//         backtracking(nums, result, subset, 0);

//         return result;
//     }

//     void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index){
//         result.push_back(subset);
        
//         for(int i = index; i < nums.size(); i++){
//             if(i > index && nums[i] == nums[i-1])   continue;
//             subset.push_back(nums[i]);
//             backtracking(nums, result, subset, i+1);
//             subset.pop_back();
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        backtracking(nums, result, subset, 0);

        return result;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index){
        if(index == nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        backtracking(nums, result, subset, index+1);
        subset.pop_back();

        while(index < nums.size()-1 && nums[index] == nums[index+1]){
            ++index;
        }        
        backtracking(nums, result, subset, index+1);
    }
};
