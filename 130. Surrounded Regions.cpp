class Solution {
public:
    void solve(vector<vector<char>>& board) {
        std::vector<std::pair<int, int>> boundCircle;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O')  boundCircle.push_back({i, 0});
            if(board[i][n-1] == 'O')    boundCircle.push_back({i, n-1});
        }
        for(int i = 1; i < n-1; i++){
            if(board[0][i] == 'O')  boundCircle.push_back({0, i});
            if(board[m-1][i] == 'O')    boundCircle.push_back({m-1, i});
        }

        std::vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(const auto& [x, y]: boundCircle){
            DFS(board, visited, x, y);
        }
        board = vector<vector<char>>(m, vector<char>(n, 'X'));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j])   board[i][j] = 'O';
            }
        }

        return;
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || \
            visited[i][j] || board[i][j] == 'X'){
                return;
        }

        visited[i][j] = true;
        DFS(board, visited, i+1, j);
        DFS(board, visited, i-1, j);
        DFS(board, visited, i, j+1);
        DFS(board, visited, i, j-1);
    }
};
