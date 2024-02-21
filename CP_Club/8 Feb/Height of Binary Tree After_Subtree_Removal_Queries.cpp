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
    map<int,int> l,r,pre;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int le = height(root->left);
        int re = height(root->right);
        l[root->val] = le;
        r[root->val] = re;
        return max(le,re)+1;      
    }
    void f(TreeNode* root,int mx,int level){
        if(root==NULL) return;
        pre[root->val] = mx;
        f(root->left,max(mx,level+r[root->val]),level+1);
        f(root->right,max(mx,level+l[root->val]),level+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        f(root->left,r[root->val],1);
        f(root->right,l[root->val],1);
        vector<int> ans;
        for(auto i: queries){
            ans.push_back(pre[i]);
        }
        return ans;
    }
};