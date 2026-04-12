class Solution {
public:
    const int INF = 1e9;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& l = nums1.size() > nums2.size() ? nums2 : nums1;
        vector<int>& r = nums1.size() > nums2.size() ? nums1 : nums2;

        int ln = l.size();
        int rn = r.size();

        int i = 0;
        int j = ln;

        while(i<j) {
            int mid = (i+j)/2;
            int lp = mid;
            int rp = (ln+rn)/2 - lp;
            cout << lp << " " << rp << endl;

            if(rp != rn && lp!=0 && r[rp] < l[lp-1]) {
                j = mid;
            } else if(lp != ln && rp!=0 && l[lp] < r[rp-1]) {
                i = mid+1;
            } else {
                i = j = mid;
                break;
            }
        }

        if ((ln+rn)%2 != 0) {
            return min(i<ln ? l[i] : INF , ((ln+rn)/2 - i) <rn ? r[(ln+rn)/2 - i] : INF);
        } else {
            cout << i << endl;
            return (min(i < ln ? l[i] : INF, ((ln+rn)/2 - i) < rn ? r[(ln+rn)/2 - i] : INF) + max(i!=0 ? l[i-1] : -1, ((ln+rn)/2 - i) !=0 ? r[(ln+rn)/2 - i -1] : -1))/2.0;
            
        }
    }
};
