// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         std::string substring = "";
//         std::vector<std::pair<int, int>> candidates;
//         for(int i = 0; i < board.size(); i++){
//             for(int j = 0; j < board[0].size(); j++){
//                 if(board[i][j] == word[0])  candidates.push_back({i, j});
//             }
//         }
//         bool result = false;
//         std::vector<vector<bool>> visited(board.size(), std::vector<bool> (board[0].size(), false));
//         for(const auto& [i, j]: candidates){
//             result |= backtracking(board, word, board.size(), board[0].size(), i, j, 0, visited);
//             if(result)  return true;
//         }

//         return false;
//     }

//     bool backtracking(vector<vector<char>>& board, string word, int row, int col, int m, int n, int index, vector<vector<bool>>& visited){
//         if(index == word.size())    return true;
//         if(m < 0 || m >= row || n < 0 || n >= col)  return false;

//         bool res;
//         if(visited[m][n] == false && board[m][n] == word[index]){
//             visited[m][n] = true;
//             res =  backtracking(board, word, row, col, m+1, n, index+1, visited) || \
//                     backtracking(board, word, row, col, m, n+1, index+1, visited) || \
//                     backtracking(board, word, row, col, m-1, n, index+1, visited) || \
//                     backtracking(board, word, row, col, m, n-1, index+1, visited);
//             visited[m][n] = false;
//             return res;
//         }

//         return false;

//     }
// };
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::string substring = "";
        std::vector<std::pair<int, int>> candidates;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0])  candidates.push_back({i, j});
            }
        }
        bool result = false;
        for(const auto& [i, j]: candidates){
            if(backtracking(board, word, board.size(), board[0].size(), i, j, 0)){
                return true;
            }
        }

        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, int row, int col, int m, int n, int index){
        if(index == word.size())    return true;
        if(m < 0 || m >= row || n < 0 || n >= col || \
            board[m][n] == '*' || board[m][n] != word[index])  return false;

        bool res;
        board[m][n] = '*';
        res =  backtracking(board, word, row, col, m+1, n, index+1) || \
                backtracking(board, word, row, col, m, n+1, index+1) || \
                backtracking(board, word, row, col, m-1, n, index+1) || \
                backtracking(board, word, row, col, m, n-1, index+1);
        board[m][n] = word[index];
        return res;
    }
};
