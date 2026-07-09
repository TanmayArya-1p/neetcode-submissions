class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> st;
        for(auto &c : s) {
            st.insert(c);
        }


        for(auto &c : t) {
            if(st.find(c) != st.end()) {
                st.erase(st.find(c));
            } else {
                return false;
            }
        }

        if(st.empty()) return true;
        return false;
    }
};
