class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, higher = 0;
        for(const auto& ch: s){
            if(ch == '('){
                ++lower, ++higher;
            }else if(ch == ')'){
                --lower, --higher;
            }else{
                --lower, ++higher;
            }

            if(higher < 0)  return false;
            if(lower < 0)   lower = 0;
        }

        return lower == 0;
    }
};
