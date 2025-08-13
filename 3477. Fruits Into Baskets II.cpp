class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), cnt = 0;
        bool find;
        for(const auto& fruit: fruits){
            find = false;
            for(int i = 0; i < n; i++){
                if(baskets[i] >= fruit){
                    baskets[i] = 0;
                    find = true;
                    break;
                }
            }
            if(!find)   ++cnt;
        }

        return cnt;
    }
};
