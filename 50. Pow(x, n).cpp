class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1;
        if(x == 1)  return 1;
        double res;
        std::unordered_map<int, double> memo;
        memo[0] = 1;
        memo[1] = x;
        memo[-1] = 1/x;

        return DFS(x, n, memo);
    }

    double DFS(double x, int n, unordered_map<int, double>& memo){
        if(memo.find(n) != memo.end()){
            return memo[n];
        }

        int a = n/2;
        int b = n/2;
        if(n%2){
            if(n < 0)   --b;
            else    ++b;
        }
        double resa = DFS(x, a, memo);
        double resb = DFS(x, b, memo);
        memo[a] = resa;
        memo[b] = resb;

        return resa * resb;
    }
};
