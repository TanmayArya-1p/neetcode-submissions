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

#define ll long long
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a.start < b.start;
        });   
        priority_queue<int, vector<int>, std::greater<int>> ends;
        int n = intervals.size();

        int mx = 0;
        for(int i = 0;i < n; i++) {
            while(!ends.empty() && ends.top() <= intervals[i].start) {
                ends.pop();
            }
            mx=max(mx, (int)ends.size()+1);
            ends.push(intervals[i].end);
        } 

        return mx;
    }
};
