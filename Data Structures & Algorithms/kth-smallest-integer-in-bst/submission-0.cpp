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
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0;

        int val = 0;
        std::function<bool(TreeNode*)> dfs = [&](TreeNode* root) mutable {
            if(root == nullptr) return false;

            if(dfs(root->left)) return true;

            ct++;
            cout << ct << endl;
            if(ct == k) {
                val = root->val;
                return true;
            }


            if(dfs(root->right)) return true;
            return false;
        };

        dfs(root);

        return val;

    }
};
