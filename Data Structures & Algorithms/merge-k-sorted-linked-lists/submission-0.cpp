#include <bits/stdc++.h>
#include <queue>
using namespace std;




class Comparator{
    public:
    bool operator()(const ListNode* a,const ListNode* b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return 0;
        int n = lists.size();
        ListNode* curr = lists[0];

        priority_queue<ListNode*, vector<ListNode*>, Comparator> mh = {};
        for(auto &i : lists) {
            if(i!=nullptr) mh.push(i);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        while(!mh.empty()) {
            head->next = mh.top();
            mh.pop();
            head = head->next;
            if(head->next != nullptr) mh.push(head->next);
        }
        return dummy->next;
    }
};

