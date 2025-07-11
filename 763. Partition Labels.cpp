// Method1: stack
class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::stack<int> stack;
        std::unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) == 0){
                map[s[i]] = i;
                stack.push(i);
            }else{
                while(!stack.empty() && stack.top() >= map[s[i]]){
                    stack.pop();
                }
                stack.push(i);
            }
        }

        std::vector<int> result;
        int prev;
        prev = stack.top();
        stack.pop();
        while(!stack.empty()){
            // cout << prev << ", " << stack.top()<< endl;
            result.insert(result.begin(), prev - stack.top());
            prev = stack.top();
            stack.pop();
        }
        result.insert(result.begin(), prev + 1);

        return result;
    }
};

// // Method2: vector
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         std::vector<int> result;
//         std::unordered_map<char, int> map;
//         for(int i = 0; i < s.size(); i++){
//             if(map.count(s[i]) == 0){
//                 map[s[i]] = i;
//                 result.push_back(i);
//             }else{
//                 while(result.size() != 0 && result.back() >= map[s[i]]){
//                     result.pop_back();
//                 }
//                 result.push_back(i);
//             }
//         }
//         for(int i = result.size()-1; i > 0; i--){
//             result[i] -= result[i-1];
//         }
//         result[0]++;

//         return result;
//     }
// };
