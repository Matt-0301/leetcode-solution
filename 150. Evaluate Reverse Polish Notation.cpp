class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        std::set<string> set =  {"+", "-", "*", "/"};
        int a, b;
        for(const auto& token: tokens){
            if(set.count(token) == 0){
                cout << "1" << ", ";
                stack.push(stoi(token));
            }else{
                cout << "2" << ", ";
                b = stack.top();
                stack.pop();
                a = stack.top();
                stack.pop();
                if(token == "+"){
                    stack.push(a + b);
                }else if(token == "-"){
                    stack.push(a - b);
                }else if(token == "*"){
                    stack.push(a * b);
                }else{
                    stack.push(a / b);
                }
            }
        }

        return stack.top();
    }
};
