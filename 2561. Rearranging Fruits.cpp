class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        std::map<int, pair<int, int>> hashmap;
        int min_cost = INT_MAX;
        for(const auto& basket: basket1){
            if(hashmap.count(basket) == 0){
                hashmap[basket] = {1, 0};
            }else{
                hashmap[basket].first++;
            }
            min_cost = std::min(min_cost, basket);
        }
        for(const auto& basket: basket2){
            if(hashmap.count(basket) == 0){
                hashmap[basket] = {0, 1};
            }else{
                hashmap[basket].second++;
            }
            min_cost = std::min(min_cost, basket);
        }
        std::vector<int> swap1, swap2;
        for(const auto& [key, p]: hashmap){
            if(p.first != p.second){
                if(p.first < p.second){
                    if((p.second-p.first)%2 != 0)   return -1;
                    for(int i = 0; i < (p.second-p.first)/2; i++){
                        swap2.push_back(key);
                    }
                }else{
                    if((p.first-p.second)%2 != 0)   return -1;
                    for(int i = 0; i < (p.first-p.second)/2; i++){
                        swap1.push_back(key);
                    }
                }
            }
        }
        // for(const auto& s: swap1){
        //     cout << s << ", ";
        // }
        // cout << endl;
        // for(const auto& s: swap2){
        //     cout << s << ", ";
        // }
        // cout << endl;
        int m = swap1.size(), n = swap2.size();
        if(m != n)    return -1;
        long long res = 0;
        int cnt = 0, left1 = 0, left2 = 0;
        while(cnt < m){
            if(left1 < m && left2 < n){
                if(swap1[left1] <= swap2[left2]){
                    res += std::min(swap1[left1], 2*min_cost);
                    ++left1;
                }else{
                    res += std::min(swap2[left2], 2*min_cost);
                    ++left2;
                }
            }else if(left1 < m){
                res += std::min(swap1[left1], 2*min_cost);
                ++left1;
            }else{
                res += std::min(swap2[left2], 2*min_cost);
                ++left2;
            }
            ++cnt;
        }

        return res;
    }
};
