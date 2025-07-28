class Solution {
public:
    int maximumGain(string s, int x, int y) {
        std::stack<char> stack;
        int cnt1 = 0, cnt2 = 0, res = 0;
        char ch1, ch2;
        if(x > y){
            ch1 = 'a', ch2 = 'b';
        }else{
            ch1 = 'b', ch2 = 'a';
            int tmp = x;
            x = y;
            y = tmp;
        }

        for(const auto& ch: s){
            if(ch == ch1){
                ++cnt1;
            }else if(ch == ch2){
                ++cnt2;
                if(cnt1 > 0){
                    res += x;
                    --cnt1, --cnt2;
                }
            }else{
                res += (std::min(cnt1, cnt2) * y);
                cnt1 = 0, cnt2 = 0;
            }
        }
        res += (std::min(cnt1, cnt2) * y);

        return res;
    }
};
