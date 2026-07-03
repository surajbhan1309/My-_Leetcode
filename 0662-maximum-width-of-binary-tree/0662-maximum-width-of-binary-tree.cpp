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
        long long ans=0;
        if(!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long base=q.front().second;
            long long first=0;
            long long last=0;
            for(int i=0;i<n;i++){
                auto node=q.front().first;
                long long idx=q.front().second-base;
                q.pop();
                if(i==0) first=idx;
                if(i==n-1) last=idx;
                if(node->left){
                    q.push({node->left,2*idx});
                }
                if(node->right){
                    q.push({node->right,2*idx+1});
                }
            }
            ans=max(ans,last-first+1);
        }        
        return ans;
    }
};