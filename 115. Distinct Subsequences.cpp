class Solution {
public:
    int numDistinct(string s, string t) {
        std::vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
        return backtrack(s, t, 0, 0, memo);
    }

    int backtrack(string& s, string& t, int indexs, int indext, vector<vector<int>>& memo){
        if(indext == t.size()){
            return 1;
        }
        if(indexs >= s.size()){
            return 0;
        }
        if(memo[indexs][indext] != -1){
            return memo[indexs][indext];
        }

        memo[indexs][indext] = 0;
        if(s[indexs] == t[indext]){
            memo[indexs][indext] += backtrack(s, t, indexs+1, indext+1, memo);
        }
        memo[indexs][indext] += backtrack(s, t, indexs+1, indext, memo);


        return memo[indexs][indext];
    }
};
