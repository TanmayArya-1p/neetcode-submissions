class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1.0/myPow(x,-n);

        if(n==1) return x;
        if(n==0) return 1;

        double r = myPow(x, n/2);
        return r*r*(n%2==1? x : 1);
    }
};
