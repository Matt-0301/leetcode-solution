class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int remove = 0;
        for(int i = 0; i < intervals.size()-1; i++){
            // cout << intervals[i][0] << ", " << intervals[i][1] << "  " << \
                intervals[i+1][0] << ", " << intervals[i+1][1] << endl;
            if(intervals[i][1] > intervals[i+1][0]){
                // if(intervals[i][1] - intervals[i][0] <= intervals[i+1][1] - intervals[i+1][0]){
                //     intervals[i+1][0] = intervals[i][0];
                //     intervals[i+1][1] = intervals[i][1];
                // }
                if(intervals[i][1] < intervals[i+1][1]){
                    intervals[i+1][1] = intervals[i][1];
                }
                ++remove;
            }
        }

        return remove;
    }
};
