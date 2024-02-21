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
    int mod = 1e9+7;
    long long ans=0,sum=0;
    int f(TreeNode* root){
        if(!root)return 0;
        int curr = f(root->left)+f(root->right)+root->val;
        ans=max(ans,(sum-curr)*curr);
        return curr;
    }
    int maxProduct(TreeNode* root) {
        sum = f(root);
        f(root);
        return ans%mod;
    }
};