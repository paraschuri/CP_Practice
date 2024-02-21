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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        int ans=1;
        while(!q.empty()){
            int a = q.size();
            bool check = 0;
            long long first =q.front().second,second=q.back().second,cmp = q.front().second;
            ans = max(ans*1ll,second-first+1);
            while(a--){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                long long curr = it.second-cmp;
                if(temp->left)q.push({temp->left,2*curr+1});
                if(temp->right)q.push({temp->right,2*curr+2});
            }
        }
        return ans;
    }
};