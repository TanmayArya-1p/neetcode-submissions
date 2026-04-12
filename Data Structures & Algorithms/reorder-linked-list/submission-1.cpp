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
    void reorderList(ListNode* head) {
        using ld = ListNode*;
        
        if(head == 0) return;

        ld slow = head;
        ld fast = head;
        ld prev = 0;
        while(fast != 0) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast == 0) break;
            fast = fast->next;
        }
        prev->next=  0;
        ld mid = slow;
        prev = 0;
        while(mid) {
            ld tmp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = tmp;
        }

        ld back = prev;
        ld curr = head;

        while(curr !=0 && back != 0) {
            ld tmp = back;
            back = back->next;
            cout << tmp->val << curr->val << endl;


            ld tmp1 = curr->next;
            curr->next = tmp;
            curr->next->next = tmp1;
            curr = curr->next->next;
        }
    }   
};
