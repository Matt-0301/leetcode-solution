class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<vector<int>> result;
        std::vector<int> subset;
        backtracking(candidates, result, target, subset, 0);

        return result;
    }

    void backtracking(vector<int>& candidates, vector<vector<int>>& result, int target, vector<int>& subset, int sum){
        if(sum > target)    return;
        if(sum == target){
            result.push_back(subset);
            return;
        }
        for(const auto& c: candidates){
            if(subset.size() != 0 && c < subset.back())   continue;
            subset.push_back(c);
            backtracking(candidates, result, target, subset, sum+c);
            subset.pop_back();
        }
    }
};
