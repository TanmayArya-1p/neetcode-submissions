class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long i=1;

        long long s = 0;
        for(auto&p : piles) s += p;

        long long j=s;

        while (i<j) {
            long long mid = (i+j)/2;
            long long t = 0;
            for(auto&p : piles) {
                t += (p/mid) + (p%mid!=0);
            }
            if(t<=h) {
                j = mid;
            } else {
                i = mid+1;
            }
        }
        return i;
    }
};
