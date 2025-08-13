class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        std::vector<vector<int>> memo(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            res = std::max(res, DFS(grid, m, n, i, 0, 0, memo)-1);
            if(res == n-1)  break;
        }
        return res;
    }

    int DFS(vector<vector<int>>& grid, int m, int n, int i, int j, int prev, vector<vector<int>>& memo){
        if(j == n || grid[i][j] <= prev){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(i == 0){
            return memo[i][j] = 1 + std::max(DFS(grid, m, n, i, j+1, grid[i][j], memo), DFS(grid, m, n, i+1, j+1, grid[i][j], memo));
        }else if(i == m-1){
            return memo[i][j] = 1 + std::max(DFS(grid, m, n, i-1, j+1, grid[i][j], memo), DFS(grid, m, n, i, j+1, grid[i][j], memo));
        }else{
            return memo[i][j] = 1 + std::max({DFS(grid, m, n, i-1, j+1, grid[i][j], memo), DFS(grid, m, n, i, j+1, grid[i][j], memo), DFS(grid, m, n, i+1, j+1, grid[i][j], memo)});
        }
    }
};
