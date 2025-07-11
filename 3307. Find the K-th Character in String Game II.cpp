class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        --k;
        if(k == 0)  return 'a';
        int op_index = 0, count = 0;
        while(k > 0){
            if(k % 2 != 0 && operations[op_index] == 1){
                ++count;
            }
            ++op_index;
            k /= 2;
        }

        return 'a' + (count % 26);
    }
};
