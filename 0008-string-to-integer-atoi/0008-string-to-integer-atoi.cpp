class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0) return 0;
        int i=0;
        while(i<n && s[i]==' ') i++;
        s=s.substr(i);
        long long ans=0;
        int sign=+1;
        if(s[0]=='-') sign=-1;
        i=(s[0]=='+' || s[0]=='-')?1:0;
        int maxi=INT_MAX,mini=INT_MIN;
        while(i<s.size()){
            if(s[0]==' '|| !isdigit(s[i])) break;
            ans=10*ans+(s[i]-'0');
            if(sign==-1 && -1*ans<mini) return mini;
            if(sign==1 && 1*ans>maxi) return maxi;
            i++;
        }
        return (int)(ans*sign);
    }
};