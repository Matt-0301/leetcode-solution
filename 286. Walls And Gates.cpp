// // Method1: DFS
// class Solution {
// public:
//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         for(int i = 0; i < grid.size(); i++){
//             for(int j = 0; j < grid[0].size(); j++){
//                 if(grid[i][j] == 0){
//                     DFS(grid, i, j, 0);
//                 }
//             }
//         }
//         return;
//     }

//     void DFS(vector<vector<int>>& grid, int i, int j, int distance){
//         if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || \
//             grid[i][j] == -1){
//             return;
//         }

//         if(grid[i][j] < distance && grid[i][j] != INT_MAX){
//             return;
//         }

//         grid[i][j] = distance;

//         DFS(grid, i+1, j, distance+1);
//         DFS(grid, i-1, j, distance+1);
//         DFS(grid, i, j+1, distance+1);
//         DFS(grid, i, j-1, distance+1);
//     }
// };

// Method1: BFS
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> queue;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    queue.push({i, j});
                }
            }
        }
        std::vector<std::pair<int, int>> dire({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        int dis = 0;
        while(!queue.empty()){
            int len = queue.size();
            ++dis;
            for(int i = 0; i < len; i++){
                pair<int, int> tmp = queue.front();
                queue.pop();
                for(const auto& [x, y]: dire){
                    int row = tmp.first+x, col = tmp.second+y;
                    if(row >= 0 && row < grid.size() && \
                        col >= 0 && col < grid[0].size() && grid[row][col] != -1){
                            if(grid[row][col] > dis){
                                grid[row][col] = dis;
                                queue.push({row, col});
                            }
                    }
                }
            }
        }
        return;
    }
};

