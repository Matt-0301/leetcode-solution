class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> dp(n+1, 0);

        int offset = 1;
        for(int i = 1; i <= n; i++){
            if(i == offset * 2){
                offset *= 2;
            }
            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
};
