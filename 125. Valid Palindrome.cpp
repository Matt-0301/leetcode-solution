class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            while(isalnum(s[left]) == false && left < s.size()-1){
                ++left;
            }
            while(isalnum(s[right]) == false && right > 0){
                --right;
            }
            if(left >= right)   return true;
            // cout << s[left] << " " << s[right] << endl;
            if((s[left] | 32) != (s[right] | 32)) return false;
            ++left;
            --right;
        }

        return true;
    }
};
