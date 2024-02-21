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
    int solve(TreeNode* root,map<TreeNode*,int> &mp){
        if(!root)return 0;
        int ans=root->val;
        if(mp.count(root)) return mp[root];
        if(root->left){
            ans+=solve(root->left->left,mp)+solve(root->left->right,mp);
        }
        if(root->right){
            ans+=solve(root->right->left,mp)+solve(root->right->right,mp);
        }
        ans = max(ans,solve(root->left,mp)+solve(root->right,mp));   
        return mp[root]=ans;
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int> mp;
        return solve(root,mp);
    }
};