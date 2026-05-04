class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>map;
        int left=0;
        int maxfreq=0;
        int ans=0;
        int n=s.size();
        for(int right=0;right<n;right++){
            map[s[right]]++;
            maxfreq=max(maxfreq,map[s[right]]);
            while((right-left+1)-maxfreq>k){
                map[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         vector<int> count(26, 0);
//         int left = 0;
//         int maxfreq = 0;
//         int ans = 0;
//         int n = s.size();
//         for(int right=0;right<n;right++){
//             count[s[right]-'A']++;
//             maxfreq=max(maxfreq,count[s[right]-'A']);
//             while(maxfreq+k<(right-left+1)){
//                 count[s[left]-'A']--;
//                 left++;
//             }
//             ans=max(ans,right-left+1);
//         }
//         return ans;
//     }
// };
