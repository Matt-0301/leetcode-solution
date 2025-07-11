class Solution {
public:
    int findLucky(vector<int>& arr) {
        int result = -1;
        std::map<int, int> map;
        for(const auto& a: arr){
            ++map[a];
        }
        for(const auto& a: map){
            if(a.first == a.second && a.first > result){
                result = a.first;
            }
        }

        return result;
    }
};
