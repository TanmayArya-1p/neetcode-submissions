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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr = new ListNode(0);  
        ListNode* org = curr;
        while(l1!=nullptr && l2 != nullptr) {
            int res = l1->val + l2->val + carry;
            int fd = res%10;
            int sd = (res - fd)/10;
            curr->next = new ListNode(fd);
            curr = curr->next;
            carry = sd;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1!=nullptr) {

            int res = l1->val + carry;
            int fd = res%10;
            int sd = (res-fd)/10;
            carry = sd;
            curr->next = new ListNode(fd);
            curr = curr->next;
            l1 = l1->next;            
        }


        while(l2!=nullptr) {

            int res = l2->val + carry;
            int fd = res%10;
            int sd = (res-fd)/10;
            carry = sd;
            curr->next = new ListNode(fd);
            curr = curr->next;
            l2 = l2->next;            
        }

        if(carry != 0) {
            curr->next = new ListNode(carry);
        }

        return org->next;
    }
};
