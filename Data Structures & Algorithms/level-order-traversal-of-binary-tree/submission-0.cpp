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


    void recur(TreeNode* root, int level, map<int, vector<int>>& mp) {
        if(root == nullptr) return;
        mp[level].push_back(root->val);
        recur(root->left, level + 1, mp);
        recur(root->right, level + 1, mp);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, std::vector<int>> mp;
        recur(root, 0, mp);
        vector<vector<int>> res;
        for(auto& [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
