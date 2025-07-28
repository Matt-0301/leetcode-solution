class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        std::unordered_map<char, int> hashmap;
        for(int i = 0; i < 26; i++){
            hashmap['a'+i] = i+1;
        }
        for(int i = 0; i < chars.size(); i++){
            hashmap[chars[i]] = vals[i];
        }
        int res = 0, cur_res = 0;
        for(const auto& ch: s){
            cur_res += hashmap[ch];

            cur_res = std::max(cur_res, 0);
            res = std::max(cur_res, res);
        }

        return res;
    }
};
