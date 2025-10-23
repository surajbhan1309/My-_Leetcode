class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n=A.size();
        stack<int>s;
        vector<int>res(n);

        for(int i=2*n-1;i>=0;i--)
        {
            int elem=A[i%n];
            while(!s.empty() && s.top()<=elem) s.pop();

            if(i<n){
            if(s.empty())res[i]=-1;
            else res[i]=s.top();
            }

            s.push(elem);
        }

        return res;
    }
};