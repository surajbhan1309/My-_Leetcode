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
    pair<bool, int> check(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};
        }

        auto left = check(root->left);
        auto right = check(root->right);

        bool balanced =
            left.first &&
            right.first &&
            abs(left.second - right.second) <= 1;

        int height = max(left.second, right.second) + 1;

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};
