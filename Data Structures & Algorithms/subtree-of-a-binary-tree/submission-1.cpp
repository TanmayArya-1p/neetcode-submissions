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
#define ll long long
    const ll MOD = 1e9+11;
    const ll P = 1091;

    ll binpow(ll a, ll b) {
        if(b==0) return 1;
        if(b==1) return a;

        ll ret = (binpow(a, b/2)%MOD * binpow(a,b/2)%MOD)%MOD * ( b%2 == 1 ? a : 1);
        ret%=MOD;
        return ret;
    }




    void compute_hashes(TreeNode* root, unordered_map<TreeNode*, ll>& hash) {
        if(root == nullptr) return;
        
        compute_hashes(root->right,hash);
        compute_hashes(root->left,hash);
        ll left = root->left ? hash[root->left] : 7;
    ll right = root->right ? hash[root->right] : 13;
        hash[root] = ((root->val*P + left*binpow(P,2))%MOD + right*binpow(P,3))%MOD;
    }

    bool recur(TreeNode* root, ll look, unordered_map<TreeNode*, ll>& hash) {
        if(root == nullptr) return false;
        
        if(hash[root] == look) {
            return true;
        }

        return recur(root->right, look, hash) || recur(root->left, look, hash);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        unordered_map<TreeNode* , ll> subroothashes;
        unordered_map<TreeNode* , ll> roothashes;

        compute_hashes(root, roothashes);        
        compute_hashes(subRoot, subroothashes);        
        return recur(root, subroothashes[subRoot] , roothashes);

    }
};
