class Solution {
public:
    bool isPalindromic(string s) {
        string str="";
       for(int i=0;i<s.size();i++){
           int a=s[i];
     str+=bitset<8>(a).to_string();
       
       }
       string rev=str;
       reverse(rev.begin(),rev.end());
       if(rev == str)
        return true;
        return false;
    }
};