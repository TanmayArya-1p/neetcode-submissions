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
        ld front = head;

        int ct = 0;
        ld temp = head;
        while(temp && (++ct)) temp=temp->next;
        int half = (ct/2) + (ct%2!=0);

        std::stack<ld> backs;
        int i = -1;
        while(front != 0) {
            ++i;
            if(i >= half) backs.push(front);
            front = front->next;
        }


        i = 0;
        front = head;
        while(i < ct/2) {
            ld pp = backs.top();
            backs.pop();

            ld tmp = front->next;
            front->next = pp;
            pp->next = tmp;
            front = tmp;
            i++;
        }
        front->next = 0;
    }
};
