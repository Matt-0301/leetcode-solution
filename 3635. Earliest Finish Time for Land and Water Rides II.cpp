class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minL = INT_MAX, minW = INT_MAX, res = INT_MAX;
        for(int i = 0; i < n; i++){
            minL = std::min(minL, landStartTime[i]+landDuration[i]);
        }
        for(int i = 0; i < m; i++){
            minW = std::min(minW, waterStartTime[i]+waterDuration[i]);

            if(minL <= waterStartTime[i]){
                res = std::min(res, waterStartTime[i] + waterDuration[i]);
            }else{
                res = std::min(res, minL + waterDuration[i]);
            }
        }

        for(int i = 0; i < n; i++){
            if(minW <= landStartTime[i]){
                res = std::min(res, landStartTime[i] + landDuration[i]);
            }else{
                res = std::min(res, minW + landDuration[i]);
            }
        }

        return res;
    }
};
