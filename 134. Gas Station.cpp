// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int current_gas, station_num, length = gas.size();
//         for(int i = 0; i < length; i++){
//             if(gas[i] >= cost[i]){
//                 int now = i;
//                 current_gas = 0;
//                 station_num = 0;
//                 while(current_gas >= 0 && station_num < length){
//                     current_gas += gas[now] - cost[now];
//                     if(current_gas < 0){
//                         break;
//                     }
//                     ++station_num;
//                     now = (now == length-1) ? 0 : ++now;
//                     // cout << current_gas << ", " << now << endl;
//                     if(station_num == length)   return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)){
            return -1;
        }
        int current_gas = 0, res = 0;
        for(int i = 0; i < gas.size(); i++){
            current_gas += gas[i] - cost[i];
            if(current_gas < 0){
                current_gas = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
