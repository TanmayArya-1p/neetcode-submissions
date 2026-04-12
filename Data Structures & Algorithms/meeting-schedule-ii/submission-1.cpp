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
        vector<ll> pref(1000002,0);
        for(auto &i : intervals) {
            pref[i.start]++;
            pref[i.end]--;
        }

        ll curr = 0;
        for(int i = 0; i< pref.size();i++) {
            curr+=pref[i];
            pref[i] = curr;
        }
        return *max_element(pref.begin(), pref.end());
    }
};
