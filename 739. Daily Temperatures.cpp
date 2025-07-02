class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> stack;
        std::vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!stack.empty() && temperatures[i] > stack.top().first){
                // cout << temperatures[i] << ", " << stack.top().first << endl;
                result[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }
        return result;
    }
};
