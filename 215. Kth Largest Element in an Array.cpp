class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>> queue;
        int i = -1;
        for(const auto& num: nums){
            queue.push({num, ++i});
        }
        for(i = 0; i < k-1; i++){
            queue.pop();
        }
        std:pair<int, int> tmp;
        tmp = queue.top();
        return tmp.first;

    }
};
