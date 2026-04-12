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

    bool mark_ancestors(TreeNode* root , set<TreeNode*>& ancestors, TreeNode* node) {
        if(root == nullptr) return false;
        if(root == node) {
            ancestors.insert(root);
            return true;
        };
        
        if(mark_ancestors(root->left, ancestors, node) || mark_ancestors(root->right, ancestors, node)) {
            ancestors.insert(root);
            return true;
        }
        return false;
    }

    void mark_heights(TreeNode* root, int height, map<TreeNode*,int>& mp) {
        if(root == nullptr) return;
        mp[root] = height;
        mark_heights(root->left, height+1, mp);
        mark_heights(root->right, height+1, mp);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        set<TreeNode*> p_ancestor;
        set<TreeNode*> q_ancestor;

        mark_ancestors(root, p_ancestor, p);
        mark_ancestors(root, q_ancestor, q);

        vector<TreeNode*> inter;
        inter.reserve(p_ancestor.size() + q_ancestor.size());

        std::set_intersection(p_ancestor.begin(), p_ancestor.end(), 
        q_ancestor.begin(), q_ancestor.end(), std::back_inserter(inter));


        map<TreeNode*, int> depths;
        mark_heights(root,0,depths);

        return *max_element(inter.begin(), inter.end(), [&](const auto& a, const auto& b) -> bool{
            return depths[a] < depths[b];
        });
    }
};
