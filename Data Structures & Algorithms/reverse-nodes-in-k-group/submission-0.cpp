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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr) return nullptr;
        if(k==1) return head;


        using ld = ListNode*;


        ld temp = head;
        int n = 0;
        while(head != nullptr && ++n) head = head->next;
        head = temp;

        if(n<k) return head;

        ld lst = nullptr;
        ld csh = head; 

        int seggs = n/k;
        int segct = 0;
        ListNode* dummy = nullptr;

        while(segct < seggs) {

            csh = head;

            ld prev = head;
            ld curr = head->next;
            int i = 1;
            while(i < k) {
                ld temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                i++;
            }
            cout << prev->val << endl;
            csh->next = curr; 

            if(lst != nullptr) lst->next = prev;

            lst = csh;

            if(dummy == nullptr) dummy = prev;
            
            head = lst->next;
            segct++;
        }


        return dummy;


    }
};
