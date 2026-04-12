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


    void precomp(TreeNode* root, map<TreeNode*,int>& minmp, map<TreeNode*,int>& maxmp) {
        if(root == nullptr) return;


        precomp(root->left, minmp, maxmp);
        precomp(root->right, minmp, maxmp);

        minmp[root] = root->val;
        maxmp[root] = root->val;

        if(root->left != nullptr && root->right != nullptr) {
            minmp[root] = min(minmp[root->left], minmp[root->right]);
            maxmp[root] = max(maxmp[root->left], maxmp[root->right]);
        } else if(root->left != nullptr) {
            minmp[root] = min(minmp[root] ,minmp[root->left]);
            maxmp[root] = max(maxmp[root] ,maxmp[root->left]);
        } else if(root->right != nullptr) {
            minmp[root] = min(minmp[root] ,minmp[root->right]);
            maxmp[root] = max(maxmp[root] ,maxmp[root->right]);
        }

    }

    bool recur(TreeNode* root,  map<TreeNode*,int>& minmp, map<TreeNode*,int>& maxmp) {
        if(root == nullptr) return true;
        if((root->left == nullptr || maxmp[root->left] < root->val) && (root->right == nullptr || minmp[root->right] > root->val)) {
            return recur(root->left, minmp, maxmp) && recur(root->right, minmp, maxmp);
        } else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
         map<TreeNode*,int> minmp;
         map<TreeNode*,int> maxmp;
         precomp(root, minmp, maxmp);
         return recur(root, minmp, maxmp);
    }
};
