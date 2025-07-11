class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end());
        std::priority_queue<int, vector<int>, greater<int>> min_heap;
        int last = 0, day = events[0][0];
        for(const auto& event: events){
            if(event[1] > last) last = event[1];
        }
        // cout << last << endl;
        int e = 0, result = 0;
        for(int i = day; i <= last; i++){
            while(e < events.size() && events[e][0] <= i){
                min_heap.push(events[e][1]);
                ++e;
            }
            while(!min_heap.empty() && min_heap.top() < i){
                min_heap.pop();
            }
            if(!min_heap.empty()){
                min_heap.pop();
                ++result;
            }
            // cout << min_heap.top() << endl;
        }

        return result;
    }
};
