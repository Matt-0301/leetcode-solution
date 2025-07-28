class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::priority_queue<pair<int, double>> cars;
        for(int i = 0; i < speed.size(); i++){
            cars.push({position[i], (double)(target-position[i])/speed[i]});
        }
        int res = 0;
        std::pair<int, double> tmp1, tmp2;
        while(!cars.empty()){
            tmp1 = cars.top();
            // cout << "1: " << tmp1.first << ", " << tmp1.second << endl;
            cars.pop();
            ++res;
            while(!cars.empty()){
                tmp2 = cars.top();
                // cout << "2: " <<  tmp2.first << ", " << tmp2.second << endl;
                if(tmp1.second < tmp2.second){
                    break;
                }
                cars.pop();
            }
        }

        return res;
    }
};
