class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<vector<int>> result;
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, result, subset, 0, 0);

        return result;

    }
    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& subset, int index, int sum){
        if(sum > target)    return;
        if(sum == target){
            result.push_back(subset);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])    continue;
            subset.push_back(candidates[i]);
            backtracking(candidates, target, result, subset, i+1, sum+candidates[i]);
            subset.pop_back();
        }
    }

};
