class Solution {
public:
    struct Compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for(const auto& num: nums){
            ++map[num];
        }
        std::priority_queue<std::pair<int, int>, \
            std::vector<std::pair<int, int>>, Compare> max_heap;
        
        for(const auto& p: map){
            max_heap.push({p.first, p.second});
        }
        std::vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(max_heap.top().first);
            max_heap.pop();
        }

        return result;
    }
};
