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
    unordered_map<TreeNode*, int> depth; 

    void update_depth(TreeNode* root) {
        if(root == nullptr) return;
        update_depth(root->right);
        update_depth(root->left);

        depth[root] = max(depth[root->right], depth[root->left])+1;
    }

    Solution() {
        depth[nullptr] = 0;
    }

    bool recur(TreeNode* root) {
        if(root == nullptr) return true;
        if(abs(depth[root->left] - depth[root->right]) > 1) {
            return false;
        }
        return recur(root->left) && recur(root->right);
    }


    bool isBalanced(TreeNode* root) {
        update_depth(root);
        return recur(root);
    }
};
