class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;


        for(int i=0;i<s.size();i++) {
            if(mp[s[i]] == 0) {
                return false;
            } else {
                mp[s[i]]--;
            }
        }
        return true;
    }
};
