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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        using ld = ListNode*;

        ld p1 = list1;
        ld p2 = list2;

        ld curr;

        if(p1==0 && p2==0) return 0;

        if(p2 == 0 || (p1!=0 && p1->val < p2->val)) {
            curr = p1;
            p1 = p1->next;
        } else {
            curr = p2;
            p2 = p2->next;
        }
        ld head = curr;

        while(p1!=0 && p2!=0) {
            if(p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }

        while(p1!=0) {
            curr->next = p1;
            p1 = p1->next;
            curr = curr->next;
        }
        while(p2!=0) {
            curr->next = p2;
            p2 = p2->next;
            curr = curr->next;
        }

        return head;

    }
};
