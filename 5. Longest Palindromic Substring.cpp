class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<int, int> maxIndex;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            // odd palindrome
            int offset = 1;
            while(i + offset < s.size() && i - offset >= 0 && s[i+offset] == s[i-offset]){
                ++offset;
            }
            --offset;
            if(offset*2+1 > maxLen){
                maxLen = offset * 2 + 1;
                maxIndex = {i-offset, i+offset};
            }
            // even palindrome
            int left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                --left,  ++right;
            }
            ++left, --right;
            if(right - left + 1 > maxLen){
                maxLen = right - left + 1;
                maxIndex = {left, right};
            }
        }

        return s.substr(maxIndex.first, maxLen);
    }
};
