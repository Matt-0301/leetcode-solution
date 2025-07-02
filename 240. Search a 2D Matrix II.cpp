// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int left, right, mid;
//         for(int i = 0; i < m; i++){
//             left = 0, right = n-1, mid = (left+right)/2;
//             while(left <= right){
//                 if(matrix[i][mid] == target){
//                     return true;
//                 }else if(matrix[i][mid] < target){
//                     left = mid + 1;
//                 }else{
//                     right = mid - 1;
//                 }

//                 mid = (left + right) / 2;
//             }
//         }

//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n-1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] < target){
                ++row;
            }else{
                --col;
            }
        }

        return false;
    }
};
