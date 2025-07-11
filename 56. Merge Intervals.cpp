class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<vector<int>> result;
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i][1] < intervals[i+1][0]){
                result.push_back(intervals[i]);
            }else{
                intervals[i+1][0] = std::min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = std::max(intervals[i][1], intervals[i+1][1]);
            }
        }
        result.push_back(intervals[intervals.size()-1]);
        return result;
    }
};
