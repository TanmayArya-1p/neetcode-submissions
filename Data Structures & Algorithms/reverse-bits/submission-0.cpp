class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t otpt = 0;
        for(int i =0;i<32;i++) {
            bool curr = n&1;
            n>>=1;
            otpt<<=1;
            otpt|= curr ? 1 : 0;
        }
        return otpt;
    }
};
