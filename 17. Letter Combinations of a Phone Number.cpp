class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::map<char, vector<char>> map = {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, \
                                            {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, \
                                            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, \
                                            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
        vector<string> result;

        backtracking(digits, result, map, "", 0);

        return result;
    }

    void backtracking(string digits, vector<string>& result, map<char, vector<char>>& map, string substring, int index){
        if(substring != "" && index == digits.size()){
            result.push_back(substring);
            return;
        }

        for(const auto& m: map[digits[index]]){
            substring += m;
            backtracking(digits, result, map, substring, index+1);
            substring.pop_back();
        }
    }
};
