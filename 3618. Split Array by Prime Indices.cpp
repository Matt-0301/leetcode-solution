class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<bool> table(n, true);
        PrimeTable(n, table);
        long long sumA = 0, sumB = 0;
        for(int i = 0; i < n; i++){
            if(table[i]){
                sumA += nums[i];
            }else{
                sumB += nums[i];
            }
        }
        return abs(sumA - sumB);
    }
    void PrimeTable(int n, vector<bool>& table){
        if(n > 1){
            table[0] = false;
            table[1] = false;
        }
        int i = 2;
        while(i < n){
            if(table[i]){
                for(int j = i+i; j < n; j += i){
                    table[j] = false;
                }            
            }
            i++;
        }
    }
};
