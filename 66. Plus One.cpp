class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i = digits.size()-1; i >= 0; i--){
            if(carry){
                ++digits[i];
            }
            if(digits[i] == 10){
                digits[i] = 0;
                // carry = true;
            }else{
                return digits;
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
