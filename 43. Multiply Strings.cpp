// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if(num1 == "0" || num2 == "0")  return "0";
//         if(num1 == "1" || num2 == "1")  return (num1 == "1") ? num2 : num1;

//         int len1 = num1.size(), len2 = num2.size();
//         string res = "";
//         for(int i = len1-1; i >= 0; i--){
//             for(int j = len2-1; j >= 0; j--){
//                 carryIn(res, (len2-j-1)+(len1-i-1), (int(num1[i]) - '0')*(int(num2[j]) - '0'));
//             }
//         }

//         return res;
//     }

//     void carryIn(string& res, int position, int c){
//         int index = res.size() - position - 1;
//         // cout << position << ", " << index << ", " << c << ", ";
//         bool carry = true;
//         while(carry && index >= 0){
//             int digit = int(res[index]) - '0';
//             digit += c;
//             if(digit < 10){
//                 carry  =false;
//             }else{
//                 c = digit / 10;
//                 digit = digit % 10;
//             }
//             res[index] = to_string(digit)[0];
//             --index;
//         }
//         if(index < 0 && carry){
//             res = to_string(c) + res;
//         }
//         // for(const auto& ch: res){
//         //     cout << ch;
//         // }
//         // cout << endl;
//     }
// };
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")  return "0";
        if(num1 == "1" || num2 == "1")  return (num1 == "1") ? num2 : num1;

        int len1 = num1.size(), len2 = num2.size();
        vector<int> res;
        for(int i = len1-1; i >= 0; i--){
            for(int j = len2-1; j >= 0; j--){
                carryIn(res, (len2-j-1)+(len1-i-1), (int(num1[i]) - '0')*(int(num2[j]) - '0'));
            }
        }

        string result = "";
        for(const auto& r: res){
            result += to_string(r);
        }

        return result;
    }

    void carryIn(vector<int>& res, int position, int c){
        int index = res.size() - position - 1;
        bool carry = true;
        while(carry && index >= 0){
            int digit = res[index];
            digit += c;
            if(digit < 10){
                carry  =false;
            }else{
                c = digit / 10;
                digit = digit % 10;
            }
            res[index] = digit;
            --index;
        }
        if(index < 0 && carry){
            if(c == 0){
                res.insert(res.begin(), c);
            }else{
                while(c > 0){
                    res.insert(res.begin(), c%10);
                    c /= 10;
                }
            }
        }
    }
};
