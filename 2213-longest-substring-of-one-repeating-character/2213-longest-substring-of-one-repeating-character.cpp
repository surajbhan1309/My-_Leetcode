class Solution {
    struct Node {
        char leftChar = 0, rightChar = 0;
        int length = 0;
        int prefix = 0, suffix = 0, best = 0;
    };

    string s;
    vector<Node> tree;

    // Merge information from two adjacent segments.
    Node merge(const Node& a, const Node& b) {
        if (a.length == 0) return b;
        if (b.length == 0) return a;

        Node res;
        res.length = a.length + b.length;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        if (a.prefix == a.length && a.rightChar == b.leftChar) {
            res.prefix = a.length + b.prefix;
        }

        res.suffix = b.suffix;
        if (b.suffix == b.length && a.rightChar == b.leftChar) {
            res.suffix = b.length + a.suffix;
        }

        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    // Build the segment tree.
    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = {s[left], s[left], 1, 1, 1, 1};
            return;
        }

        int mid = left + (right - left) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    // Apply a point update and recompute affected ancestors.
    void update(int node, int left, int right, int index, char value) {
        if (left == right) {
            s[index] = value;
            tree[node] = {value, value, 1, 1, 1, 1};
            return;
        }

        int mid = left + (right - left) / 2;
        if (index <= mid) {
            update(node * 2, left, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, right, index, value);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        int n = s.size();
        tree.assign(4 * n + 5, Node());

        build(1, 0, n - 1);

        vector<int> answer;
        answer.reserve(queryIndices.size());

        for (int i = 0; i < queryIndices.size(); ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};