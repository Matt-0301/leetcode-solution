class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;
        for(int i = 0; i < n-1; i++){
            for(int j = 1; j < n; j++){
                if(i < j){
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
        }
        // for(const auto& row: matrix){
        //     for(const auto& i: row){
        //         cout << i << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for(int row = 0; row < n; row++){
            int left = 0, right = n-1;
            while(left < right){
                tmp = matrix[row][left];
                matrix[row][left] = matrix[row][right];
                matrix[row][right] = tmp;
                ++left, --right;
            }
        }
        return;
    }
};
