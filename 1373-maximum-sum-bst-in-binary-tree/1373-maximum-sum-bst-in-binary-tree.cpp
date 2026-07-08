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
class Box {
public:
    bool bst;
    int sum;
    int max_val, min_val;

    Box() {
        bst = true;
        sum = 0;
        max_val = INT_MIN;
        min_val = INT_MAX;
    }
};

class Solution {
public:
    Box find(TreeNode* root, int& tsum) {
        if (!root)
            return Box();

        Box lh = find(root->left, tsum);
        Box rh = find(root->right, tsum);

        if (lh.bst && rh.bst && lh.max_val < root->val && rh.min_val > root->val) {
            Box head;
            head.sum = root->val + lh.sum + rh.sum;
            head.min_val = min(lh.min_val, root->val);
            head.max_val = max(rh.max_val, root->val);

            tsum = max(tsum, head.sum);
            return head;
        } 
        else {
            Box head;
            head.bst = false;
            return head;
        }
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        find(root, sum);
        return sum;
    }
};
