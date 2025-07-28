// // Method1: dynamic programming(top-down)
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         std::unordered_set<string> set;
//         for(const auto& word: wordDict){
//             set.insert(word);
//         }
//         std::vector<bool> dp(s.size(), false);
//         std::set<int> findSet;
//         for(int i = 0; i < s.size(); i++){
//             if(set.count(s.substr(0, i+1))){
//                 dp[i] = true;
//                 findSet.insert(i);
//             }else{
//                 for(const auto& index: findSet){
//                     if(index < i && set.count(s.substr(index+1, i-index))){
//                         dp[i] = true;
//                         findSet.insert(i);
//                     }
//                 }
//             }
//         }
//         // for(const auto& d: dp){
//         //     cout << d << ", ";
//         // }
//         // cout << endl;
//         return dp[s.size()-1];
//     }
// };
// Method2: dynamic programming(bottom-up)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        for(int i = s.size()-1; i >= 0; i--){
            for(const auto& word: wordDict){
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word){
                    dp[i] = dp[i+word.size()];
                }
                if(dp[i])   break;
            }
        }

        return dp[0];
    }
};
