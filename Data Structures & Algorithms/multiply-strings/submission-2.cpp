class Solution {
public:
    #define ll long long

    ll binexp(int a, int n) {
        if(n==0) return 1;
        if(n==1) return a;

        ll r = binexp(a, n/2);
        return r*r*(n%2==1? a : 1);
    }

    string lltos(ll x) {
        if(x == 0) return "0";

        string otpt;
        while(x>0) {
            otpt = (char)('0' + x%10) + otpt;
            x/= 10;
        }
        return otpt;
    }

    string multiply(string num1, string num2) {
        ll otpt=0;
        for(int i = 0;i < num1.size() ;i++) {
            for(int j = 0;j < num2.size() ;j++) {
                otpt += binexp(10,i+j) * (num1[num1.size()-i-1] - '0') * (num2[num2.size()-j-1] - '0');
            }
        }
        return lltos(otpt);
    }
};
