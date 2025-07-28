class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        std::vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));

        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    if(DFS(grid, i, j, k) == 0){
                        ++res;
                    }                    
                }
            }
        }

        return res;
    }
    int DFS(vector<vector<int>>& grid, int i, int j, int k){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int res = 0;
        res += grid[i][j] % k;
        grid[i][j] = 0;
        res += DFS(grid, i+1, j, k) % k;
        res += DFS(grid, i-1, j, k) % k;
        res += DFS(grid, i, j+1, k) % k;
        res += DFS(grid, i, j-1, k) % k;

        return res % k;
    }
};
