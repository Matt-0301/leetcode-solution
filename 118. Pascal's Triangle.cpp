class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<vector<int>> res;
        std::vector<int> tmp;
        res.push_back({1});
        for(int i = 0; i < numRows-1; i++){
            tmp.push_back(1);
            for(int j = 1; j < res[i].size(); j++){
                tmp.push_back(res[i][j]+res[i][j-1]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }

        return res;
    }
};
