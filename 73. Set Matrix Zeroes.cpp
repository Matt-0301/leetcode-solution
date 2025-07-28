class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<pair<int, int>> zero;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    zero.push_back({i, j});
                }
            }
        }
        for(const auto& [i, j]: zero){
            setZero(matrix, i, j, m, n);
        }
    }

    void setZero(vector<vector<int>>& matrix, int row, int col, int m, int n){
        for(int i = 0; i < m; i++){
            matrix[i][col] = 0;
        }
        for(int i = 0; i < n; i++){
            matrix[row][i] = 0;
        }
    }
};
