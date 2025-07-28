class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        std::map<int, int> hashmap;
        for(const auto& query: queries){
            hashmap[query] = -1;
        }
        int index = 0;
        for(const auto& [query, s]: hashmap){
            // cout << "query: " << query << endl;
            while(index < intervals.size() && intervals[index][0] <= query){
                minHeap.push({intervals[index][1] - intervals[index][0] + 1, intervals[index][1]});
                ++index;
            }
            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }
            // cout << minHeap.empty() << ", " << minHeap.top().first << ", " << minHeap.top().second << endl;
            if(!minHeap.empty()){
                hashmap[query] = minHeap.top().first;
            }
        }

        std::vector<int> result;
        for(const auto& q: queries){
            result.push_back(hashmap[q]);
        }

        return result;
    }
};
