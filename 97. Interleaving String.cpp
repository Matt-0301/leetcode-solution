class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())  return false;
        std::vector<vector<int>> memo(s1.size()+1, vector<int>(s2.size()+1, -1));
        return backtrack(s1, s2, s3, 0, 0, 0, memo);
    }

    bool backtrack(string& s1, string& s2, string& s3, int i1, int i2, int i3, vector<vector<int>>& memo){
        if(i3 == s3.size()){
            if(i1 == s1.size() && i2 == s2.size())  return true;
            else return false;
        }
        if(i1 > s1.size() || i2 > s2.size())    return false;
        if(s1[i1] != s3[i3] && s2[i2] != s3[i3]){
            return false;
        }
        if(memo[i1][i2] != -1)    return memo[i1][i2];

        bool b1 = false, b2 = false;
        if(s1[i1] == s3[i3]){
            b1 = backtrack(s1, s2, s3, i1+1, i2, i3+1, memo);
        }
        if(s2[i2] == s3[i3]){
            b2 = backtrack(s1, s2, s3, i1, i2+1, i3+1, memo);
        }

        memo[i1][i2] = b1 || b2;

        return memo[i1][i2];
    }
};
