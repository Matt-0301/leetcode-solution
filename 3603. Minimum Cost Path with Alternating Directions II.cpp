class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        std::vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX));
        waitCost[0][0] = 1;
        dp[0][0] = 0;
        for(int j = 1; j < n; j++){
            dp[0][j] = (1)*(j+1) + dp[0][j-1] + waitCost[0][j-1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[i][j] = (i+1)*(j+1) + dp[i-1][j] + waitCost[i-1][j];
                }else{
                    dp[i][j] = (i+1)*(j+1) + \
                        std::min(dp[i-1][j] + waitCost[i-1][j], \
                                dp[i][j-1] + waitCost[i][j-1]);
                }
            }
        }
        // for(const auto& row: dp){
        //     for(const auto& val: row){
        //         cout << val << ", ";
        //     }
        //     cout << endl;
        // }
        return dp[m-1][n-1];
    }
};
