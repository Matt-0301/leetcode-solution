class Solution {
public:
    bool isAnagram(string s, string t) {
        std::multiset<char> set;
        for(const auto& ch: s){
            set.insert(ch);
        }
        for(const auto&ch: t){
            if(set.find(ch) == set.end())   return false;
            set.erase(set.find(ch));
        }
        if(set.empty()) return true;
        return false;
    }
};
