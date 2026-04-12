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

    void recur(TreeNode* root, int level, map<int, int>& mp) {
        if(root == nullptr) return;
        mp[level] = root->val;
        recur(root->left, level + 1, mp);
        recur(root->right, level + 1, mp);
    }

    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;
        recur(root, 0, mp);
        vector<int> res;
        for(auto& [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
