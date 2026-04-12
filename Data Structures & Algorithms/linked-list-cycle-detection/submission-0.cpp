/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        using ld = ListNode*;

        ld p1 = head;
        ld p2 = head;

        while(p1 !=0 && p2 != 0) {
            p1 = p1->next;
            
            p2 = p2->next;
            if(p2 == 0) return false;
            p2 = p2->next;

            if(p1 == p2) return true;
        }

        return false;

    }
};
