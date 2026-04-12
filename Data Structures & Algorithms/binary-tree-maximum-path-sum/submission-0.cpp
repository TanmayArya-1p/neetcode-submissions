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
    void recur(TreeNode* root, map<TreeNode*, int>& maxEndings) {
        if(root == nullptr) return;
        maxEndings[root] = root->val;

        recur(root->left, maxEndings);
        recur(root->right, maxEndings);

        if(root->left) {
            maxEndings[root] = max(maxEndings[root], maxEndings[root->left]+root->val);
        }

        if(root->right) {
            maxEndings[root] = max(maxEndings[root], maxEndings[root->right]+root->val);
        }
    }

    int ans(TreeNode* root, map<TreeNode*, int> maxEndings) {
        int curr = root->val;
        curr = max(curr, maxEndings[root->left] + root->val);
        curr = max(curr, maxEndings[root->right] + root->val);
        curr = max(curr, maxEndings[root->left] + maxEndings[root->right] + root->val);

        if(root->left) curr = max(curr, ans(root->left, maxEndings));
        if(root->right) curr = max(curr, ans(root->right, maxEndings));
        return curr;
    }

    int maxPathSum(TreeNode* root) {
        map<TreeNode*, int> maxEndings;
        recur(root, maxEndings);
        return ans(root, maxEndings);
    }
};
