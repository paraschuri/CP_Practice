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
    static const int n=1e5+1;
    vector<int> adj[n];
    void build(TreeNode* root){
        if(!root)return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right);
        }
    }
    int dfs(int node,int parent){
        int ans=0;
        for(auto i: adj[node]){
            if(i!=parent){
                ans=max(ans,1+dfs(i,node));
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        build(root);
        return dfs(start,-1);
    }
};