class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> occ;
        for(auto &c: s) occ[c]++;

        vector<int> ans;

        int curr = 0;
        int erased =0;
        unordered_set<char> currocc;
        
        for(int i = 0;i < s.size(); i++) {
            curr++;
            if(currocc.find(s[i]) != currocc.end()) {
                cout << s[i] << "CURR " << curr << endl;
                occ[s[i]]--;
                if(occ[s[i]]==0) {
                    erased++;
                }
                if(erased == currocc.size()) {
                    ans.push_back(curr);
                    curr = 0;
                    currocc = {};
                    erased = 0;
                }
            } else {
                cout << s[i] << "CURR new " << curr << endl;
                occ[s[i]]--;
                if(occ[s[i]] == 0) {
                    if(currocc.size() == 0) {
                        ans.push_back(curr);
                        curr = 0;
                    }
                    continue;
                }
                currocc.insert(s[i]);
            }
        }
        if(curr != 0) {
            ans.push_back(curr);
        }
        return ans;
    }
};
