// // Method1: map
// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if(hand.size() % groupSize != 0)   return false;
//         std::map<int, int> map;
//         for(const auto& h: hand){
//             ++map[h];
//         }
//         int count = 0;
//         std::vector<int> ready_erase;
//         while(count < hand.size()){
//             int prev_val = -1, i = 0;
//             for(const auto& m: map){
//                 if(prev_val != -1 && prev_val + 1 != m.first){
//                     return false;
//                 }
//                 prev_val = m.first;
//                 --map[m.first];
//                 if(m.second == 0){
//                     ready_erase.push_back(m.first);
//                 }
//                 ++i;
//                 ++count;
//                 if(i == groupSize){
//                     break;
//                 }
//             }
//             if(i != groupSize)  return false;
//             for(const auto& m: ready_erase){
//                 map.erase(m);
//             }
//             ready_erase.clear();
//         }
//         return true;
//     }
// };

// Method2: hashmap
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)    return false;
        std::unordered_map<int, int> hashmap;
        for(const auto& h: hand){
            ++hashmap[h];
        }
        int count = 0;
        for(const auto& h: hand){
            if(hashmap[h] > 0){
                int i = h;
                while(hashmap[i-1] > 0){
                    --i;
                }
                while(i <= h){
                    while(hashmap[i] > 0){
                        for(int j = i; j < i+groupSize; j++){
                            if(hashmap.count(j) == 0 || hashmap[j] <= 0)   return false;
                            --hashmap[j];
                            ++count;
                        }
                    }
                    ++i;
                }
            }
        }
        // cout << hand.size() << ", " << count << endl;
        return count == hand.size();
    }
};
