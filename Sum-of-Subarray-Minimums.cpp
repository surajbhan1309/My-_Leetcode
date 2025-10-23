class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        int n=arr.size();
        int mod=1e9+7;
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
        
    }
    vector<int> findnse(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findpsee(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
};