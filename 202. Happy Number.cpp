class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        int sum = 0;
        while(!set.count(sum)){
            set.insert(sum);
            sum = 0;
            while(n != 0){
                int m = n%10;
                sum += m * m;
                n = n/10;
            }
            if(sum == 1)    return true;
            n = sum;
            // cout << sum << ", " << n << endl;
        }

        return false;
    }
};
