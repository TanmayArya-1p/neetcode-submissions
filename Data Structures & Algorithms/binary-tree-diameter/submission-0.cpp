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

    int recurse(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(depth[root->right]+depth[root->left]+1, max(recurse(root->left), recurse(root->right)));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        update_depth(root);
        return recurse(root)-1;
    }
};
