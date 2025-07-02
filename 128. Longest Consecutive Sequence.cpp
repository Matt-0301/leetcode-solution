class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set;
        // std::unordered_set<int> has_found;

        for(const auto& num: nums){
            set.insert(num);
        }
        int LCS = 0, local, tmp;
        // for(const auto& s: set){
        //     if(has_found.count(s) == 0){
        //         has_found.insert(s);
        //         local = 1;
        //         tmp = s-1;
        //         while(set.count(tmp)){
        //             has_found.insert(tmp);
        //             ++local;
        //             --tmp;
        //         }
        //         tmp = s+1;
        //         while(set.count(tmp)){
        //             has_found.insert(tmp);
        //             ++local;
        //             ++tmp;
        //         }
        //         if(local > LCS) LCS = local;
        //     }
        // }
        for(const auto& s:set){
            if(set.count(s-1) == 0){
                local = 1;
                tmp = s+1;
                while(set.count(tmp++)){
                    ++local;
                }
                if(local > LCS) LCS = local;
            }
        }

        return LCS;
    }
};
