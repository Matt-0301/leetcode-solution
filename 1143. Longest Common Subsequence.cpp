// // Method1:DP(top-dwon) 
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         std::vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
//         return backtrack(text1, text2, 0, 0, memo);
//     }

//     int backtrack(string& text1, string& text2, int index1, int index2, vector<vector<int>>& memo){
//         if(index1 == text1.size() || index2 == text2.size()){
//             return 0;
//         }
//         if(memo[index1][index2] != -1){
//             return memo[index1][index2];
//         }

//         if(text1[index1] == text2[index2]){
//             memo[index1][index2] = 1 + backtrack(text1, text2, index1+1, index2+1, memo);
//         }else{
//             memo[index1][index2] = std::max(backtrack(text1, text2, index1+1, index2, memo), \
//                                     backtrack(text1, text2, index1, index2+1, memo));
//         }

//         return memo[index1][index2];
//     }
// };

// Method2: DP(bottom-up)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
