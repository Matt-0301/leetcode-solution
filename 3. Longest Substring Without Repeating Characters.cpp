class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set;
        int longest = 0, tmp = 0;
        for(int i = 0; i < s.size(); i++){
            if(set.count(s[i]) == 0){
                set.insert(s[i]);
                ++tmp;
            }else{
                if(tmp > longest)   longest = tmp;
                while(s[i] != s[i-tmp]){
                    set.erase(s[i-tmp]);
                    --tmp;
                }
            }
        }
        if(tmp > longest)   return tmp;
        return longest;
    }
};
