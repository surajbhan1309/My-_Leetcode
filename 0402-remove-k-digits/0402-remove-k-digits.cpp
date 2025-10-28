class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.size();
        if(n<=k) return "0";
        if(k==0) return num;
        string ans="";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);

            if(st.size()==1 && num[i]=='0'){
                st.pop();
            }
            
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "0";
        }
        return ans;
        
        
    }
};