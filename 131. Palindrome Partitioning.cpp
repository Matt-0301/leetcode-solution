class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<vector<string>> result;
        std::vector<string> substring;
        backtracking(s, result, substring, 0, 0);

        return result;
    }
    void backtracking(string& s, vector<vector<string>>& result, vector<string>& substring, int cutleft, int cutright){
        if(cutright == s.size()){
            if(cutleft == s.size()){
                result.push_back(substring);
                return;
            }
            return;
        }

        string sub = s.substr(cutleft, cutright-cutleft+1);
        if(isPalindrome(sub)){
            substring.push_back(sub);
            backtracking(s, result, substring, cutright+1, cutright+1);
            substring.pop_back();
        }
        backtracking(s, result, substring, cutleft, cutright+1);

    }

    bool isPalindrome(string& s){
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};
