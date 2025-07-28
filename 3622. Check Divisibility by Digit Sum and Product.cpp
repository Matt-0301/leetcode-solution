class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1;
        int tmp = n;
        while(n > 0){
            s += n % 10;
            p *= n % 10;
            n /= 10;
        }
        // cout << s << ", " << p << endl; 
        if(tmp % (s+p) == 0){
            return true;
        }
        return false;
    }
};
