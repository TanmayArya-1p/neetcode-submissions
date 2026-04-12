#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr ll INF = 1e8;

class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;


        unordered_map<char, int> freq;
        unordered_map<char,int> occur;

        int completed = 0;
        for (auto &c : t) {
            occur[c]++;
            if (occur[c] == 1) {
                completed++;
            }
        }


        int ans = INF;
        pair<int,int> ansp;

        if (occur[s[i]] > 0) {
            freq[s[i]]++;
            if(freq[s[i]] == occur[s[i]]) {
                completed--;
            }
        }

        while (i<=j && j < s.length()) {
            if(completed == 0) {
                ans = min(ans, j-i+1);
                if (ans == j-i+1) {
                    ansp = {i,j};
                }
                if (occur[s[i]] == 0 || (occur[s[i]] > 0 && freq[s[i]] > occur[s[i]])) {
                    freq[s[i]]--;
                    i++;
                } else {
                    // cannot trim no longer
                    freq[s[i]]--;
                    i++;
                    completed++;
                }
            } else {
                if(j == s.length()-1) {
                    break;
                }
                if(occur[s[j+1]] != 0) {
                    freq[s[j+1]]++;
                    if(freq[s[j+1]] == occur[s[j+1]]) {
                        completed--;
                    }
                }
                j++;
            }
        }

        if(completed == 0) {
            ans = min(ans, j-i+1);
            if (ans == j-i+1) {
                ansp = {i,j};
            }
        }
        if (ans == INF) {
            return "";
        }
        return s.substr(ansp.first,ansp.second-ansp.first+1);
    }
};



// int main() {
//     Solution* s = new Solution();
//     std::cout << s->minWindow("ADOBECODEBANC", "ABC") << std::endl;;
// }
