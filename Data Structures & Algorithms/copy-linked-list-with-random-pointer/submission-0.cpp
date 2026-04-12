/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> otn;

        Node* org = head;
        while(head != nullptr) {
            Node* nn = new Node(head->val);
            otn[head] = nn;
            head = head->next;
        }   

        head = org;
        while(head != nullptr) {
            Node* nn = otn[head];
            nn->next = otn[head->next];
            nn->random = otn[head->random];
            head = head->next;
        }
        return otn[org];
    }
};
