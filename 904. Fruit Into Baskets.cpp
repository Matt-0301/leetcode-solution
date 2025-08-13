class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::unordered_map<int, int> hashmap;
        int left = 0, res = 0;
        for(int i = 0; i < fruits.size(); i++){
            ++hashmap[fruits[i]];
            while(hashmap.size() > 2){
                --hashmap[fruits[left]];
                if(hashmap[fruits[left]] == 0){
                    hashmap.erase(fruits[left]);
                }
                ++left;
            }
            res = std::max(res, i-left+1);
        }

        return res;
    }
};
