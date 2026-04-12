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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a.start < b.end;
        });   
        int n = intervals.size();
        for(int i =0; i<n-1;i++) {
            if(intervals[i+1].start >= intervals[i].end) continue;
            else return false;
        }
        return true;
    }
};
