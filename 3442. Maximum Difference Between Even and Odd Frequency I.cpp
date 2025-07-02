class Solution {
public:
    int maxDifference(string s) {
        std::unordered_map<char, int> dict;
        for(const auto & c: s){
            ++dict[c];
        }
        int max_odd = 0, min_even = 100;
        int tmp;
        // for(std::map<char, int>::iterator iter = dict.begin(); iter != dict.end(); iter++){
        for(const auto& iter: dict){
            tmp = iter.second;
            if(tmp % 2 == 0){
                if(tmp < min_even)  min_even = tmp;
            }else{
                if(tmp > max_odd)  max_odd = tmp;
            }
        }
        // cout << max_odd << " " << min_odd << endl;
        // cout << max_even << " " << min_even << endl;
        return max_odd - min_even;
    }
};
