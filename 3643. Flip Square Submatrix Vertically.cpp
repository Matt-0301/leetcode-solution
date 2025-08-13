class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int up = x, down = x+k-1;
        int tmp;
        while(up < down){
            for(int j = y; j < y+k; j++){
                tmp = grid[up][j];
                grid[up][j] = grid[down][j];
                grid[down][j] = tmp;
            }
            ++up, --down;
        }

        return grid;
    }
};
