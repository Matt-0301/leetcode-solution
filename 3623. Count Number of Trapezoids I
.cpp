class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        std::unordered_map<int, long long> map;
        long long res = 0, mod = 1000000007;
        
        for(const auto& point: points){
            ++map[point[1]];
        }
        std::vector<int> toerase;
        for(const auto& m: map){
            if(m.second < 2){
                toerase.push_back(m.first);
            }else{
                // x.push_back(m.first);
                map[m.first] = (m.second * (m.second-1) / 2) % mod;
            }
        }
        for(const auto& e: toerase){
            map.erase(e);
        }
        if(map.size() == 1){
            return 0;
        }

        long long prefix = 0;
        for(const auto& [key, value]: map){
            res  = (res + (value * prefix % mod)) % mod;
            prefix = (prefix + value) % mod;
        }
        
        return (int)res;
    }
};
