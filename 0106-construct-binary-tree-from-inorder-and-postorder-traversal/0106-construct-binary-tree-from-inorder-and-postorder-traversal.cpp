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
    unordered_map<int,int>pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            pos[inorder[i]]=i;
        }
        return build(postorder,0,inorder.size()-1,postIdx);
    }
    TreeNode* build(vector<int>& postorder,int inStart,int inEnd,int &postIdx){
        if(inStart>inEnd) return NULL;
        int rootVal=postorder[postIdx--];
        TreeNode* root=new TreeNode(rootVal);
        int idx=pos[rootVal];
        root->right=build(postorder,idx+1,inEnd,postIdx);
        root->left=build(postorder,inStart,idx-1,postIdx);
        return root;
    }
};