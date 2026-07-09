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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int,int> order;
        for(int i =0 ; i < n ; i++) {
            order[inorder[i]] = i;
        }

        TreeNode* curr = new TreeNode{preorder[0]};
        TreeNode* dummy = new TreeNode(-1e8);
        order[-1e8] = 1e9;
        int p = 1;

        function<void(TreeNode* root, TreeNode* prev)> recur = [&](TreeNode* root, TreeNode* prev) {
            if(p < n) {
                int cons = preorder[p];
                if(order[cons] < order[root->val]) {
                    TreeNode* nn = new TreeNode{cons};
                    root->left = nn;
                    p++;
                    recur(nn, root);
                }
            }
            if(p < n) {
                int cons = preorder[p];            
                if(order[cons] < order[prev->val]) {
                    TreeNode* nn = new TreeNode{cons};
                    root->right = nn;
                    p++;
                    recur(nn, prev);
                }
            }
        };

        recur(curr, dummy);
        return curr;
    }
};
