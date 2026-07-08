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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=-1;
        TreeNode* current=root;
        while(current){
            if(current->left==NULL){
                count++;
                if(count==k) ans=current->val;
                current=current->right;
            }
            else{
                TreeNode* Predecessor=current->left;
                while(Predecessor->right!=NULL && Predecessor->right!=current){
                    Predecessor=Predecessor->right;
                }
                if(Predecessor->right==NULL){
                    Predecessor->right=current;
                    current=current->left;
                }
                else{
                    Predecessor->right=NULL;
                    count++;
                    if(count==k) ans=current->val;
                    current=current->right;
                }
            }
        }
        return ans;
    }
};