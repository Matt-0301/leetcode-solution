class Solution {
public:
    int maxDiff(int num) {
        string MAX = to_string(num), MIN = MAX;
        char X1, X2, R2;
        bool B1 = false, B2 = false;
        for(int i = 0; i < MAX.size(); i++){
            if(!B1){
                if(MAX[i] != '9'){
                    B1 = true;
                    X1 = MAX[i];
                    MAX[i] = '9';
                }
            }else{
                if(MAX[i] == X1){
                    MAX[i] = '9';
                }
            }
        }
        for(int i = 0; i < MIN.size(); i++){
            if(!B2){
                if(MIN[i] != '1' && i == 0){
                    B2 = true;
                    R2 = '1';
                    X2 = MIN[i];
                    MIN[i] = R2;
                }else if(MIN[i] != '1' && MIN[i] != '0' && i != 0){
                    B2 = true;
                    R2 = '0';
                    X2 = MIN[i];
                    MIN[i] = R2;
                }
            }else{
                if(MIN[i] == X2){
                    MIN[i] = R2;
                }
            }
        }
        // cout << stoi(MAX) << " " << stoi(MIN) << endl;
        return stoi(MAX) - stoi(MIN);
    }
};
