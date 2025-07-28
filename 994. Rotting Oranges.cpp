class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> queue;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) ++fresh;
                else if(grid[i][j] == 2)    queue.push({i, j});
            }
        }
        if(fresh == 0)  return 0;
        std::vector<std::pair<int, int>> direct({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        int minute = 0;
        while(!queue.empty()){
            int len = queue.size();
            ++minute;
            for(int i = 0; i < len; i++){
                std::pair<int, int> tmp = queue.front();
                queue.pop();
                for(const auto& [x, y]: direct){
                    int row = tmp.first + x, col = tmp.second + y;
                    if(row >= 0 && row < grid.size() && \
                         col >= 0 && col < grid[0].size() && grid[row][col] == 1){
                            grid[row][col] = 2;
                            queue.push({row, col});
                            --fresh;
                    }
                }

                if(fresh == 0)  return minute;
            }
        }

        return -1;
    }
};
