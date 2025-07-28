class Solution {
public:
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     std::priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
    //     int dist;
    //     for(const auto& point: points){
    //         dist = point[0]*point[0] + point[1]*point[1];
    //         minHeap.push({dist, point});
    //     }
    //     std::vector<vector<int>> result;
    //     while(k > 0){
    //         result.push_back(minHeap.top().second);
    //         minHeap.pop();
    //         --k;
    //     }

    //     return result;
    // }
    struct myCompare{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<vector<int>, vector<vector<int>>, myCompare> minHeap;
        for(const auto& point: points){
            minHeap.push(point);
        }
        std::vector<vector<int>> result;
        while(k > 0){
            result.push_back(minHeap.top());
            minHeap.pop();
            --k;
        }

        return result;
    }

};
