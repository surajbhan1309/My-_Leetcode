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
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        int val=-1;
        solve(root,mini,val);
        return mini;
    }
    void solve(TreeNode* root,int &mini,int &val){
        if(!root) return;
        if(root->left){
            solve(root->left,mini,val);
        }
        if(val>=0)mini=min(mini,abs(root->val-val));
        val=root->val;
        if(root->right){
            solve(root->right,mini,val); 
        }
    }
};