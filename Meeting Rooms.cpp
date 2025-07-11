/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// class Solution {
// public:
//     bool canAttendMeetings(vector<Interval>& intervals) {
//         std::map<int, int> map;
//         for(const auto& interval: intervals){
//             ++map[interval.start];
//             --map[interval.end];
//         }
//         int curr = 0;
//         for(const auto& m: map){
//             curr += m.second;
//             if(curr != 1 && curr != 0){
//                 return false;
//             }
//         }
//         // cout << intervals[0].start << endl;

//         return true;
//     }
// };
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[i-1].end){
                return false;
            }
        }

        return true;
    }
};

