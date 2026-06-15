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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}}); // node, {col, row}

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode* node = cur.first;
            int col = cur.second.first;
            int row = cur.second.second;

            mp[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});

            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> ans;

        for (auto &c : mp) {
            vector<int> temp;
            for (auto &r : c.second) {
                temp.insert(temp.end(),r.second.begin(),r.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};