class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> result;
        string stack;
        backtracking(result, n, n, stack);

        return result;
    }

    void backtracking(std::vector<string> &result, int open, int close, string &stack){
        if(open == 0 && close == 0){
            result.push_back(stack);
            return;
        }

        if(close > open){
            stack += ')';
            backtracking(result, open, close-1, stack);
            stack.pop_back();
        }
        if(open > 0){
            stack += '(';
            backtracking(result, open-1, close, stack);
            stack.pop_back();
        }
    }
};
