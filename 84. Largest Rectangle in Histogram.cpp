class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<pair<int, int>> stack;
        int c, res = 0;
        for(int i = 0; i < heights.size(); i++){
            c = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                pair<int, int> top = stack.top();
                c = top.first;
                if((i - top.first) * top.second > res){
                    res = (i - top.first) * top.second;
                }
                stack.pop();
            }
            stack.push({c, heights[i]});
        }

        c = heights.size();
        while(!stack.empty()){
            pair<int, int> top = stack.top();
            if((c - top.first) * top.second > res){
                res = (c - top.first) * top.second;
            }
            stack.pop();
        }

        return res;
    }
};
