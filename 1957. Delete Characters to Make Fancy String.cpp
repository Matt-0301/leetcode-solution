// // Method1: string erase(slower)
// class Solution {
// public:
//     string makeFancyString(string s) {
//         int n = s.size(), cnt = 1;
//         for(int i = n-1; i >= 1; i--){
//             if(s[i] == s[i-1]){
//                 cnt++;
//             }else{
//                 cnt = 1;
//             }
//             if(cnt >= 3){
//                 s.erase(s.begin()+i);
//             }
//         }

//         return s;
//     }
// };

// Method2: creatr a empty string and append it(faster)
class Solution {
public:
    string makeFancyString(string s) {
        string res;
        res += s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                ++cnt;
            }else{
                cnt = 1;
            }
            if(cnt < 3){
                res += s[i];
            }
        }

        return res;
    }
};
