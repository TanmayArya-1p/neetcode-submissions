class Solution {
public:
#define ll long long
    int reverse(int x) {
        ll otpt=0;
        bool neg = x < 0;
        if(neg) x = -x;


        while(x > 0) {
            int curr = x%10;
            x/=10;
            otpt*=10;
            otpt+= curr;
            if(otpt > INT_MAX) {
                return 0;
            }
        }
        return otpt * (neg ? -1 : 1);
    }
};
