class Solution {
public:
    vector<int> countBits(int n) {
        // 1 1 2 1 2 2 3 1 2 2 3 
        vector<int> otpt(n+1,0);
        for(uint i = 0;i <= n; i++) {
            otpt[i] = popcount(i);
        }
        return otpt;
    }
};
