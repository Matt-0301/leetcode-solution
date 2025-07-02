class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::map<char, int> map_s1;
        std::map<char, int> map_s2;
        for(const auto& ch: s1){
            ++map_s1[ch];
        }
        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            if(map_s1.find(s2[right]) == map_s1.end()){
                map_s2.clear();
                left = right + 1;
            }else{
                ++map_s2[s2[right]];
                while(map_s2[s2[right]] > map_s1[s2[right]]){
                    --map_s2[s2[left]];
                    ++left;
                }

                if(map_s1 == map_s2)    return true;
            }
        }

        return false;
    }
};
