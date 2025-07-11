class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size(), 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            if(dp[i-1] <= dp[i-2]){
                dp[i] = dp[i-1] + cost[i];
            }else{
                dp[i] = dp[i-2] + cost[i];
            }
        }

        return std::min(dp[cost.size()-2], dp[cost.size()-1]);
    }
};
