class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        std::vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                int tmp = backtrack(matrix, i, j, INT_MIN, memo);
                res = (tmp > res) ? tmp : res;
            }
        }

        return res;
    }

    int backtrack(vector<vector<int>>& matrix, int i, int j, int prevVal, vector<vector<int>>& memo){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prevVal){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        memo[i][j] =  1 + std::max({backtrack(matrix, i+1, j, matrix[i][j], memo), \
                                    backtrack(matrix, i-1, j, matrix[i][j], memo), \
                                    backtrack(matrix, i, j+1, matrix[i][j], memo), \
                                backtrack(matrix, i, j-1, matrix[i][j], memo)});

        return memo[i][j];
    }
};
