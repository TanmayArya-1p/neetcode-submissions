/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void recur(TreeNode* root, int maxval, int& ct) {
        if(root == nullptr) return;
        if(root->val >= maxval) ct++;
        maxval = max(maxval, root->val);
        recur(root->right, maxval, ct);
        recur(root->left, maxval, ct);
    }


    int goodNodes(TreeNode* root) {
        int ct = 0;
        recur(root, root->val, ct);
        return ct;
    }
};
