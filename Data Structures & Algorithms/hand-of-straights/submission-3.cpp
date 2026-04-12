class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        if(n==1 || groupSize==1) return true;
        
        int ng = n/groupSize;
        
        priority_queue<int , vector<int>, std::greater<int>> q;
        unordered_map<int,int> cts;


        for(auto&h : hand) q.push(h);
        for(auto&h : hand) cts[h]++;

        while(!q.empty()) {
            int curr = q.top();
            q.pop();
            if(cts[curr] == 0) continue;
            cts[curr]--;
            for(int i=0;i<groupSize-1;i++) {
                int alt = curr+i+1;
                if(cts[alt] == 0) return false;

                cts[alt]--;
            }
        }
        return true;

    }
};
