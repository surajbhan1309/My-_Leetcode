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
    TreeNode* minVal(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
    if (root == NULL) {
        return NULL;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else { // Node found
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child (left child only)
        if (root->left != NULL && root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 1 child (right child only)
        if (root->left == NULL && root->right != NULL) {
           TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if (root->left != NULL && root->right != NULL) {
            TreeNode* temp = minVal(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
        
    }
};