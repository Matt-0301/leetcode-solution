class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int tmp, result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    tmp = DFS(grid, i, j);
                    result = (result < tmp) ? tmp : result;
                }
            }
        }

        return result;
    }
    int DFS(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0){
            return 0;
        }

        grid[row][col] = 0;
        return 1 + DFS(grid, row+1, col) + DFS(grid, row-1, col) + \
                    DFS(grid, row, col+1) + DFS(grid, row, col-1);
    }
};
