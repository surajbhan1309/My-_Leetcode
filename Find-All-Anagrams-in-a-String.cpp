class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(auto &x:p){
            need[x]++;
        }
        int left=0,right=0;
        int valid=0;
        vector<int>result;
        while(right<s.size()){
            char c=s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }
            while((right-left) >= p.size()){
                if(valid==need.size()){
                    result.push_back(left);
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
        return result;

        
    }
};