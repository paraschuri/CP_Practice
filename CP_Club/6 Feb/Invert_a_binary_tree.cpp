class Solution {
public:
    void solve(TreeNode* old){
        if(!old)return;
        solve(old->left);
        solve(old->right);
        swap(old->left,old->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};