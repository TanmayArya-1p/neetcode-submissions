class Solution {
public:

    bool isAnagram(string& a, string& b) {
        unordered_map<char,int> mp;
        for(auto &c : a) mp[c]++;

        for(int i=0;i<b.size();i++) {
            if(mp.find(b[i]) == mp.end()) {
                return false;
            }
            mp[b[i]]--;
        }
        for(auto &t: mp) {
            if(t.second != 0) return false;
        }
        return true;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> otpt;
        int n = strs.size();
        vector<int> assign(n, -1);
        for(int i =0; i<n; i++) {
            if(assign[i] != -1) continue;
            vector<string> lol = {strs[i]};
            for(int j =i+1; j<n; j++) {
                if(isAnagram(strs[i], strs[j])) {
                    assign[j] = 0;
                    lol.push_back(strs[j]);
                }
            }
            otpt.push_back(lol);
        }   
        return otpt;

    }
};
