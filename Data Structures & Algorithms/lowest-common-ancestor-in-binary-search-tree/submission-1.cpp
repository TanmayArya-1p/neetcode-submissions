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

    TreeNode* recur(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        if(p->val < root->val && q->val < root->val) {
            return recur(root->left, p , q);
        }
        if(p->val > root->val && q->val > root->val) {
            return recur(root->right, p , q);
        } else {
            return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recur(root, p, q);
    }
};
