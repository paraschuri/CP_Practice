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
    vector<int> a,b;
    void dfs(TreeNode* root,bool f){
        if(!root)return;
        if(!root->left && !root->right){
            if(f)a.push_back(root->val);
            else b.push_back(root->val);
        }
        dfs(root->left,f);
        dfs(root->right,f);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,1);
        dfs(root2,0);
        if(a.size()!=b.size())return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
};