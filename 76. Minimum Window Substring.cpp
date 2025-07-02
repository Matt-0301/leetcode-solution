class Solution {
public:
    string minWindow(string s, string t) {
        std::map<char, int> map_t;
        std::map<char, int> map_s;
        std::unordered_set<char> finish_s;
        for(const auto& ch: t){
            ++map_t[ch];
        }
        int left = 0, minimum = s.size(), min_left = 0;
        bool flag = false;
        for(int right = 0; right < s.size(); right++){
            if(map_t.find(s[right]) != map_t.end()){
                ++map_s[s[right]];
                if(map_s[s[right]] == map_t[s[right]]){
                    finish_s.insert(s[right]);
                }
                while(finish_s.size() == map_t.size()){
                    flag = true;
                    if(right-left+1 < minimum){
                        minimum = right-left+1;
                        min_left = left;
                    }
                    if(map_s.find(s[left]) != map_s.end()){
                        --map_s[s[left]];
                        if(map_s[s[left]] < map_t[s[left]]){
                            finish_s.erase(s[left]);
                        }
                    }
                    ++left;
                }
            }
            // cout << "left: " << left << ", right: " << right << ", " << s[left] << " " << s[right] << endl;
        }
        if(!flag)   return "";
        string result = s.substr(min_left, minimum);
        return result;
    }
};
