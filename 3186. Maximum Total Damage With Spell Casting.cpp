class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::vector<pair<int, long long>> dp;
        std::sort(power.begin(), power.end());

        for(const auto& p: power){
            if(dp.size() > 0 && p == dp.back().first){
                ++dp.back().second;
            }else{
                dp.push_back({p, 1});
            }
        }

        // for(const auto& d: dp){
        //     cout << d.first << ", " << d.second << endl;
        // }

        for(int i = 0; i < dp.size(); i++){
            dp[i].second = dp[i].first * dp[i].second;
            int c = i-1;
            while(c >= 0 && dp[i].first - dp[c].first <= 2){
                --c;
            }
            if(c >= 0)  dp[i].second += dp[c].second;

            if(i >= 1 && dp[i].first - dp[i-1].first <= 2){
                dp[i].second = std::max(dp[i-1].second, dp[i].second);
            }
            if(i >= 2 && dp[i].first - dp[i-2].first <= 2){
                dp[i].second = std::max(dp[i-2].second, dp[i].second);
            }
        }

        // return 0;
        return dp[dp.size()-1].second;
    }
};
