class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<unordered_map<char, int>> row(9);
        std::vector<unordered_map<char, int>> col(9);
        std::vector<unordered_map<char, int>> sub_box(9);
        char ch;
        for(int i = 0; i < 9; i++){
            for(int j = 2; j < 36; j+=4){
                ch = board[i][(j-2) / 4];
                if(ch != '.'){
                    int tmp = i;
                    if(row[tmp].find(ch) != row[tmp].end()) return false;
                    ++row[tmp][ch];
                    tmp = (j-2) / 4;
                    if(col[tmp].find(ch) != col[tmp].end()) return false;
                    ++col[tmp][ch];
                    tmp = (i/3)*3 + ((j-2) / 4)/3;
                    if(sub_box[tmp].find(ch) != sub_box[tmp].end()) return false;
                    ++sub_box[tmp][ch];
                }
            }
        }

        return true;
    }
};
