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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        using ld = ListNode*;

        ld curr = head;
        ld prev = 0;
        while(curr != 0) {
            ld temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ld tail = prev;
        prev = 0;
        int ct = 1;
        
        while(ct < n) {
            ld temp = tail->next;
            tail->next = prev;
            prev = tail;
            tail = temp;
            ct++;
        }

        // x x x<-x x y->y->y->y->0
        //            ^ ^
        //             t p      
        // remove tail

        if(prev == 0 && tail->next == 0) return 0;
        if(tail->next == 0) return prev;


        if(prev != 0) {
            ld temp = tail->next->next;
            tail->next->next = prev;
            prev = tail->next;
            tail = temp;
        } else {
            tail = tail->next;
        }


        while(tail!=0) {
            ld temp = tail->next;
            tail->next = prev;
            prev = tail;
            tail = temp;
        }
        return prev;
    }
};
