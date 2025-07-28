class Solution {
public:
    int countSubstrings(string s) {
        int mid, result = s.size();
        int left, right;
        for(int i = 0; i < s.size(); i++){
            left = i-1, right = i+1;
            while(left >= 0 && right < s.size()){ // odd palindrome
                if(s[left] == s[right]){
                    ++result;
                }else{
                    break;
                }
                --left, ++right;
            }

            left = i, right = i+1;
            while(left >= 0 && right < s.size()){    // even palindrome
                if(s[left] == s[right]){
                    ++result;
                }else{
                    break;
                }
                --left, ++right;
            }
        }

        return result;
    }
};
