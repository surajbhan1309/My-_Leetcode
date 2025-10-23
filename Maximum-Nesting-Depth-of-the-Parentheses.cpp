class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                if(!st.empty()){
                int n=st.size();
                maxi=max(maxi,n);
                }
            }
            else if(s[i]==')'){
                st.pop();
            }
            else{
            continue;
            }
        }
    return maxi;  
    }
    

};