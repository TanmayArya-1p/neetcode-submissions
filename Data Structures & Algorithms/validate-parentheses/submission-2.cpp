#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    char rev_bracket(char c) {
        switch(c) {
            case '}':
                return '{';
            case ')':
                return '(';
            case ']':
                return '[';
            default:
                throw invalid_argument("invalid");
        }
    }



    bool isValid(string s) {
        std::stack<int> q;
        for(auto &c : s) {
            if(c == '[' ||c == '{' ||c == '(' ) {
                q.push(c);
            } else if (c == '}' || c == ')' ||c == ']' ) {
                if(q.size() == 0) {
                    return false;
                }

                if(q.top() == rev_bracket(c)) {
                    q.pop();
                } else {
                    return false;
                }
            }
        }
        return (q.size() == 0);
    }
};
