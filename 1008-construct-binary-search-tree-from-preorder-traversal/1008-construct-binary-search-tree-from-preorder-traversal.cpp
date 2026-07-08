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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int start=0;
     return build(preorder,start,INT_MAX);
    }
    TreeNode* build(vector<int>&preorder,int &start,int end){
        if(start==preorder.size()||preorder[start]>end) return NULL;
        TreeNode* root= new TreeNode(preorder[start++]);
        root->left=build(preorder,start,root->val);
        root->right=build(preorder,start,end);
        return root;
    }
};