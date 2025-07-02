class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        int coda = 0, l, r;
        while(left<right){
            // cout << s[left] << ", " << s[right] << endl;
            if(s[left] != s[right]){
                if(coda == 1){
                    // cout << "s[l] = " << s[l] << ", s[r]: " << s[r] << endl; 
                    if(s[l] != s[r])    return false;
                    coda = 2;
                    left = l+1;
                    right = r-1;
                    continue;
                }else if(coda == 2){
                    return false;
                }
                if(left+1 <= right && s[left+1] == s[right]){
                    // cout << "replace: " << s[left+1] << ", " << s[right] << endl;
                    l = left;
                    r = right-1;
                    ++left;
                    coda = 1;
                    continue;
                }else if(left <= right-1 && s[left] == s[right-1]){
                    // cout << "replace: " << s[left] << ", " << s[right-1] << endl;
                    --right;
                    coda = 2;
                    continue;
                }else{
                    return false;
                }
            }
            ++left;
            --right;
        }

        return true;
    }
};
