// // Method 1: DP(top-down)
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         std::vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
//         return DFS(grid, 0, 0, memo);
//     }

//     int DFS(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& memo){
//         if(x >= grid.size() || y >= grid[0].size()){
//             return 0;
//         }
//         if(memo[x][y] != -1){
//             return memo[x][y];
//         }
//         if(x == grid.size()-1){
//             return memo[x][y] = grid[x][y] + DFS(grid, x, y+1, memo);
//         }
//         if(y == grid[0].size()-1){
//             return memo[x][y] = grid[x][y] + DFS(grid, x+1, y, memo);
//         }

//         return memo[x][y] = grid[x][y] + std::min(DFS(grid, x, y+1, memo), DFS(grid, x+1, y, memo));
//     }
// };

// Method 2: DP(bottom-up)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + std::min(dp[i][j-1], dp[i-1][j]);
            }
        }

        return dp[m-1][n-1];
    }
};
