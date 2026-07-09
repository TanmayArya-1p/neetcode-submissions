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
    int diameterOfBinaryTree(TreeNode* root) {
        

        int ans = -1;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if(root == nullptr) return 0;

            int a1 = dfs(root->left);
            int a2 = dfs(root->right);
            ans = max(ans, a1 + a2 + 1);
            return max(a1, a2) + 1;
        };
        dfs(root);

        return ans-1;
    }
};
