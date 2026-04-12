class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ct = 0;
        while(n!=0) {
            if(n&1 == 1) ct++;
            n = n >>1;
        }
        return ct;
    }
};
