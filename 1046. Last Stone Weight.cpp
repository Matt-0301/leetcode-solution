class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for(const auto& stone: stones){
            maxHeap.push(stone);
        }

        int x, y;
        while(!maxHeap.empty()){
            y = maxHeap.top();
            maxHeap.pop();
            if(maxHeap.empty()) return y;
            x = maxHeap.top();
            maxHeap.pop();
            if(x != y){
                maxHeap.push(y - x);
            }
        }

        return 0;
    }
};
