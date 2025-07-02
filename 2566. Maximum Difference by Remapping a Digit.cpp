class Solution {
public:
    int minMaxDifference(int num) {
        string MAX = to_string(num);
        string MIN = MAX;
        int i = 0;
        while(i < MAX.size() && MAX[i] == '9'){
            i++;
        }
        int first_digit = MAX[i];
        for(; i < MAX.size(); i++){
            if(first_digit == MAX[i]){
                MAX[i] = '9';
            }
        }
        first_digit = MIN[0];
        for(i = 0; i < MIN.size(); i++){
            if(first_digit == MIN[i]){
                MIN[i] = '0';
            }
        }
        return stoi(MAX) - stoi(MIN);
    }
};
