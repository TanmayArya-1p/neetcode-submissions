class Solution {
public:
    bool checkValidString(string s) {
        int lcount = 0;
        int star = 0;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '(') lcount++;
            else if(s[i] == ')') {
                lcount--;
                if(lcount<0) {
                    if(star>0) {
                        lcount = 0;
                        star--;
                    } else {
                        return false;
                    }
                }
            }
            else star++;
        }

        int lstar = 0;
        int rcount = 0;
        for(int i = s.size()-1; i>= 0; i--) {
            if(s[i] == ')') rcount++;
            else if(s[i] == '(') {
                rcount--;
                if(rcount<0) {
                    if(lstar>0) {
                        rcount = 0;
                        lstar--;
                    } else {
                        return false;
                    }
                }
            }
            else lstar=min(lstar+1, star);
        }
        return true;
    }
};
