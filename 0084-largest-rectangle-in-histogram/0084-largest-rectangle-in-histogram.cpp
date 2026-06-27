class Solution {
public:

    vector<int> nextSmallerElements(vector<int>& arr, int n) {
        vector<int> v(n);
        stack<int> s;

        for (int i=n-1; i>=0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            v[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prevSmallerElements(vector<int>& arr, int n) {
        vector<int> v(n);
        stack<int> s;

        for (int i=0; i<n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            v[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElements(heights, n);
        vector<int> prev = prevSmallerElements(heights, n);

        int area = INT_MIN;

        for (int i=0; i<n; i++) {
            int l = heights[i];
            int nextIdx = (next[i] == -1) ? n : next[i];
            int b = nextIdx - prev[i] - 1;

            int ans = l*b;
            area = max(area, ans);
        }
        return area;
    }
};
