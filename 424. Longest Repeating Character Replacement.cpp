class Solution {
public:
    int characterReplacement(string s, int k) {
        std::map<char, int> map;
        int max_freq = 0, left = 0, longest = 0, tmp = 0;
        for(int i = 0; i < s.size(); i++){
            ++map[s[i]];
            max_freq = std::max(max_freq, map[s[i]]);

            while((i - left + 1) - max_freq > k){
                if(tmp > longest)   longest = tmp;
                --map[s[left]];
                ++left;
                --tmp;
            }

            ++tmp;
        }

        if(tmp > longest)   return tmp;
        return longest;
    }
};
