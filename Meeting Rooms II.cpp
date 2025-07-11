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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        std::multiset<int> set;
        bool flag;
        for(int i = 0; i < intervals.size(); i++){
            flag = false;
            for(const auto& s: set){
                if(s <= intervals[i].start){
                    flag = true;
                    set.erase(set.lower_bound(s));
                    set.insert(intervals[i].end);
                    break;
                }
            }
            if(!flag){
                set.insert(intervals[i].end);
            }
            // for(const auto& s:set){
            //     cout << s << ", ";
            // }
            // cout << endl;
        }

        return set.size();
    }
};

