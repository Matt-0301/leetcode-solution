// class Solution {
// public:
//     int numberOfWays(int n, int x) {
//         std::vector<int> dp(n+1, 0);
//         dp[0] = 0;
//         int num = 1;
//         while(pow(num, x) <= n){
//             ++num;
//         }
//         cout << num << endl;
//         for(num = num-1; num > 0; num--){
//             for(int i = n; i >= num; i--){
//                 int tmp = pow(num, x);
//                 if(i-tmp >= 0){
//                     ++dp[i-tmp];
//                 }
//             }
//         }

//         return dp[0];
//     }
// };
class Solution {
public:
    const int MOD = 1000000007;
    int numberOfWays(int n, int x) {
        int num = 1;
        while(pow(num, x) <= n){
            ++num;
        }
        std::vector<vector<uint32_t>> memo(num+1, vector<uint32_t>(n+1, -1));
        return DFS(n, x, num-1, memo);
    }

    int DFS(int n, int x, int num, vector<vector<uint32_t>>& memo){
        if(n == 0){
            return 1;
        }
        if(n < 0 || num <= 0){
            return INT_MIN;
        }
        if(memo[num][n] != -1){
            return memo[num][n];
        }

        // return std::max(0, DFS(n, x, num-1)) + std::max(0, DFS(n-pow(num, x), x, num-1));
        return memo[num][n] = (std::max(0, DFS(n, x, num-1, memo))%MOD + \
                std::max(0, DFS(n-pow(num, x), x, num-1, memo))%MOD)%MOD;
    }
};
