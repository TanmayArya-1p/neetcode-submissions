class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> cars;
        for(int i = 0; i < n ; i++) {
            cars.emplace_back(position[i] , speed[i]);
        }

        sort(cars.begin(), cars.end());
        
        vector<float> ttr(n, -1);
        for(int i = 0 ; i < n ; i++) {
            auto &[cpos, cspeed] = cars[i];
            ttr[i] = ((target - cpos)*1.0)/cspeed;
        }

        stack<int> st;
        vector<int> fgt(n, -1);
        for(int i = n-1 ;i >= 0; i--) {
            while(!st.empty() && ttr[st.top()] < ttr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                fgt[i] = st.top();
            }
            st.push(i);
        }


        int curr = 0;
        int ct = 0;
        while(curr < n) {
            int last = curr;
            while(curr != -1) {
                cout << curr << " ";
                last = curr;
                curr = fgt[curr];
            }
            cout << endl;
            ct++;
            curr = last + 1;
        }

        return ct;

    }
};
