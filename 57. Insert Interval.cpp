class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<vector<int>> result;
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin()+i, intervals.end());
                return result;
            }else if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }else{
                newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
                newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
            }
        }
        // if(result.empty() || result[result.size()-1][1] < newInterval[0])  result.push_back(newInterval);
        result.push_back(newInterval);
        return result;
    }
};
