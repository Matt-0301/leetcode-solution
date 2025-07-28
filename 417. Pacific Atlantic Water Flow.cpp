class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        std::vector<vector<bool>> Pacific(m, vector<bool>(n, false));
        std::vector<vector<bool>> Atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            DFS(heights, Pacific, i, 0, -1);
        }
        for(int i = 0; i < n; i++){
            DFS(heights, Pacific, 0, i, -1);
        }

        for(int i = 0; i < m; i++){
            DFS(heights, Atlantic, i, n-1, -1);
        }
        for(int i = 0; i < n; i++){
            DFS(heights, Atlantic, m-1, i, -1);
        }

        std::vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& hashmap, int i, int j, int prevVal){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || \
                hashmap[i][j] || heights[i][j] < prevVal){
            return;
        }

        hashmap[i][j] = true;
        DFS(heights, hashmap, i+1, j, heights[i][j]);
        DFS(heights, hashmap, i-1, j, heights[i][j]);
        DFS(heights, hashmap, i, j+1, heights[i][j]);
        DFS(heights, hashmap, i, j-1, heights[i][j]);
    }
};
