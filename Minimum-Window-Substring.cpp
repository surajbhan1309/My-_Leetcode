class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;

        for(auto &x:p){
            need[x]++;
        }
        int left=0,right=0;
        int valid=0;
        int start=0;
        int len=INT_MAX;

        while(right<s.size()){
            char c=s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }
            while(valid==need.size()){
                if(right-left < len){
                    start=left;
                    len=right-left;
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d]){
                        valid--;
                    }
                    window[d]--;
                }

            }
        }
        return len==INT_MAX?"":s.substr(start,len);

        
    }
};