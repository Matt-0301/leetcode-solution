// // Method 1: DP(top-down)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size(), res = INT_MAX;
//         std::vector<vector<int>> memo(m, vector<int>(n, -101));
//         for(int i = 0; i < n; i++){
//             res = std::min(res, DFS(matrix, m, n, 0, i, memo));
//         }
//         return res;
//     }

//     int DFS(vector<vector<int>>& matrix, int m, int n, int x, int y, vector<vector<int>>& memo){
//         if(x == m){
//             return 0;
//         }
//         if(memo[x][y] != -101){
//             return memo[x][y];
//         }

//         if(y == 0){
//             return memo[x][y] = matrix[x][y] + std::min(DFS(matrix, m, n, x+1, y, memo), \
//                                 DFS(matrix, m, n, x+1, y+1, memo));
//         }else if(y == n-1){
//             return memo[x][y] = matrix[x][y] + std::min(DFS(matrix, m, n, x+1, y, memo), \
//                                 DFS(matrix, m, n, x+1, y-1, memo));
//         }else{
//             return memo[x][y] = matrix[x][y] + std::min({DFS(matrix, m, n, x+1, y-1, memo), \
//                             DFS(matrix, m, n, x+1, y, memo), DFS(matrix, m, n, x+1, y+1, memo)});
//         }
//     }
// };

// Method 2: DP(bottom-up)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<vector<int>> dp(m, vector<int>(n, -101));
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < m; i++){
            dp[i][0] = matrix[i][0] + std::min(dp[i-1][0], dp[i-1][1]);
            dp[i][n-1] = matrix[i][n-1] + std::min(dp[i-1][n-1], dp[i-1][n-2]);
            for(int j = 1; j < n-1; j++){
                dp[i][j] = matrix[i][j] + std::min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
