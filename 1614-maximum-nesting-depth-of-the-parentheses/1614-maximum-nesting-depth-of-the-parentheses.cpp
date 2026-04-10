class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                int size_Stack=st.size();
                ans=max(ans,size_Stack);
            }
            else if(s[i]==')'){
                st.pop();
            }
            else{
                continue;
            }
        }
        return ans;
    }
};