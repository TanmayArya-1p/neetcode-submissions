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
    ListNode* reverseList(ListNode* head) {
        using ld = ListNode*;
        ld curr = head;
        ld prev = 0;

        while(curr != 0) {
            ld tmp = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = tmp;
        }
        return prev;
    }   
};
