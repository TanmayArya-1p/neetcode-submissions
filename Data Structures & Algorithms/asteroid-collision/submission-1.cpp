class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> rights;
        vector<int> otpt;
        for(int i= 0; i<n; i++) {
            if(a[i]>0) {
                rights.push(a[i]);
            } else {

                bool bk = false;
                while(!rights.empty()) {
                    int currtop = rights.top();
                    rights.pop();

                    if(currtop > -a[i]) {
                        rights.push(currtop);
                        break;
                    } else if(currtop == -a[i]) {
                        bk = true;
                        break;
                    }
                }
                if(!bk && rights.empty()) {
                    otpt.push_back(a[i]);
                }
            }
        }
        vector<int> temp;
        while(!rights.empty()) {
            temp.push_back(rights.top());
            rights.pop();
        }
        for(int i =temp.size()-1; i>=0;i--) otpt.push_back(temp[i]);
        return otpt;
    }
};