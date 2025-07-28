class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, vector<pair<int, int>>> adjList;

        for(const auto& time: times){
            adjList[time[0]].emplace_back(time[1], time[2]);
        }

        std::set<int> visited;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        std::pair<int, int> tmp;
        int res;

        minHeap.push({0, k});
        while(!minHeap.empty()){
            tmp = minHeap.top();
            minHeap.pop();
            if(visited.count(tmp.second))   continue;
            visited.insert(tmp.second);
            res = tmp.first;
            for(const auto& adj: adjList[tmp.second]){
                minHeap.push({tmp.first + adj.second, adj.first});
            }
        }

        if(visited.size() != n) return -1;
        return res;
    }
};
