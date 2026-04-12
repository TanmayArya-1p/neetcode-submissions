/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* generateNode(Node* node, unordered_map<Node*, Node*>& oldtonew) {
        Node* newNode = new Node(node->val);
        oldtonew[node] = newNode;        

        for(Node* i: node->neighbors) {
            if(oldtonew.find(i) != oldtonew.end()) {
                newNode->neighbors.push_back(oldtonew[i]);
                continue;
            } 
            newNode->neighbors.push_back(generateNode(i, oldtonew));
        }

        return newNode;
    }


    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        unordered_map<Node*, Node*> oldtonew;
        return generateNode(node, oldtonew);
    }
};
