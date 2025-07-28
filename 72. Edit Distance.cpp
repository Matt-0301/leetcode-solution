class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));

        return backtrack(word1, word2, 0, 0, memo);
    }

    int backtrack(string& word1, string& word2, int index1, int index2, vector<vector<int>>& memo){
        if(index2 == word2.size())  return word1.size() - index1;
        if(index1 >= word1.size())  return word2.size() - index2;
        if(memo[index1][index2] != -1)  return memo[index1][index2];

        if(word1[index1] == word2[index2]){
            memo[index1][index2] = backtrack(word1, word2, index1+1, index2+1, memo);
        }else{  // insert, delete, replace
            memo[index1][index2] = 1 + std::min({backtrack(word1, word2, index1, index2+1, memo), \
                            backtrack(word1, word2, index1+1, index2, memo), \
                            backtrack(word1, word2, index1+1, index2+1, memo)});
        }

        return memo[index1][index2];
    }
};
