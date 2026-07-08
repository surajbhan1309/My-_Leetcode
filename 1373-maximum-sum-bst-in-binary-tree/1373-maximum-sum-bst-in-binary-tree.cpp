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
class NodeValue {
public:
    int minNode, maxNode, sum;
    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};
class Solution {
public:
    NodeValue f(TreeNode* root, int& ans) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto l = f(root->left, ans);
        auto r = f(root->right, ans);
        if (root->val > l.maxNode && root->val < r.minNode) {
            int currSum = l.sum + r.sum + root->val;
            ans = max(ans, currSum);
            return NodeValue(
                min(root->val, l.minNode),
                max(root->val, r.maxNode),
                currSum
            );
        }
        return NodeValue(INT_MIN, INT_MAX, max(l.sum, r.sum));
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
};