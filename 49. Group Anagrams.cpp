class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // std::vector<vector<string>> result;
        // std::map< map<char, int>, std::vector<string>> map;
        // std::map<char, int> tmp;
        // for(const auto& str: strs){
        //     for(const auto& ch: str){
        //         ++tmp[ch];
        //     }
        //     map[tmp].push_back(str);
        //     tmp.clear();
        // }
        // for(const auto& m: map){
        //     result.push_back(m.second);
        // }
        // return result;
        std::unordered_map<string, vector<string>> map;
        string tmp;
        for(const auto& str: strs){
            tmp = str;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(str);
        }

        std::vector<vector<string>> result;
        for(const auto& m: map){
            result.push_back(m.second);
        }

        return result;
    }
};
