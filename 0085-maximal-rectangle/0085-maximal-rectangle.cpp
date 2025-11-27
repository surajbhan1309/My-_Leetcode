class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>prefix(n,vector<int>(m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0'){
                    sum=0;
                    prefix[i][j]=0;
                }
                prefix[i][j]=sum;
            }
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int area=largestRectangleArea(prefix[i]);
            maxarea=max(area,maxarea);
        }
        return maxarea;
        
    }
       vector<int> nextSmallerElements(vector<int> arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prevSmallerElements(vector<int> arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i=0; i<n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElements(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElements(heights, n);

        int area = INT_MIN;

        for (int i=0; i<n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            int ans = l*b;
            area = max(area, ans);
        }
        return area;
    }
};