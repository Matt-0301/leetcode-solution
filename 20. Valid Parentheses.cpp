class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack_;
        char tmp;
        for(const auto& ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stack_.push(ch);
            }else{
                if(stack_.empty())  return false;
                if(ch == ')'){
                    tmp = stack_.top();
                    if(tmp == '(')  stack_.pop();
                    else    return false;
                }else if(ch == ']'){
                    tmp = stack_.top();
                    if(tmp == '[')  stack_.pop();
                    else    return false;
                }else{
                    tmp = stack_.top();
                    if(tmp == '{')  stack_.pop();
                    else    return false;
                }
            }
        }
        if(stack_.empty())  return true;
        return false;
    }
};
