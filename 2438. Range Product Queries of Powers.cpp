class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        std::vector<int> powers;
        int i = 0;
        while(n != 0){
            if(n & 1){
                powers.push_back((int)pow(2, i));
            }
            n = n >> 1;
            ++i;
        }
        // for(const auto& power: powers){
        //     cout << power << ", ";
        // }
        // cout << endl;
        std::vector<int> res;
        long long tmp;
        for(const auto& query: queries){
            tmp = 1;
            for(int i = query[0]; i <= query[1]; i++){
                tmp = (tmp * powers[i]) % MOD;
            }
            res.push_back(tmp);
        }
        return res;
    }
};
