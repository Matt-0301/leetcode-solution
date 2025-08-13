class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        std::vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(32, -1)));
        return DFS(grid, k, m, n, 0, 0, 0, memo);
    }

    int DFS(vector<vector<int>>& grid, int k, int m, int n, \
            int x, int y, int val, vector<vector<vector<int>>>& memo){
        if(x >= m || y >= n){
            return (val == k) ? 1 : 0;
        }
        if(memo[x][y][val] != -1){
            return memo[x][y][val];
        }

        if(x == m-1){
            return memo[x][y][val] = DFS(grid, k, m, n, x, y+1, val^grid[x][y], memo)%1000000007;
        }else if(y == n-1){
            return memo[x][y][val] = DFS(grid, k, m, n, x+1, y, val^grid[x][y], memo)%1000000007;
        }

        return memo[x][y][val] = (DFS(grid, k, m, n, x, y+1, val^grid[x][y], memo)%1000000007 + \
                    DFS(grid, k, m, n, x+1, y, val^grid[x][y], memo)%1000000007)%1000000007;         
    }
};
