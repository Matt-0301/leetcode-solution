class Solution {
public:
    char kthCharacter(int k) {
        --k;
        if(k == 0)  return 'a';
        int count = 0;
        while(k > 0){
            if(k % 2 != 0){
                ++count;
            }
            k /= 2;
        }
        return 'a' + count;
    }
};
