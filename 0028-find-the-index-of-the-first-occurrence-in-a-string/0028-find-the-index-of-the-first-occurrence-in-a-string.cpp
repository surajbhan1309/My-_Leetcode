// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(haystack.find(needle)<haystack.size()){
//             return haystack.find(needle);
//         }
//         return -1;
        
//     }
// };

class Solution {
public:
    // --- APPROACH 1: Z-ALGORITHM ---
    vector<int> buildZ(string s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                Z[i] = min(r - i + 1, Z[i - l]);
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
                Z[i]++;
            if (Z[i] > 0 && i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        return Z;
    }

    // --- APPROACH 2: KMP (LPS) ---
    vector<int> buildLPS(string pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while(i < n) {
            if(pat[i] == pat[j]) {
                lps[i++] = ++j;
            } else {
                if(j != 0) j = lps[j-1];
                else lps[i++] = 0;
            }
        }
        return lps;
    }

     // --- APPROACH 4: Rolling Hash  ---
    int RollingHashSearch(string &haystack,string &needle){
        typedef long long ll;
        int n=haystack.size();
        int m=needle.size();
        ll base = 31;
        ll patHash = 0;
        ll textHash = 0;
        ll h= 1;
        ll MOD = 1e9 + 7;
        for(int i=0;i<m-1;i++){
            h=(h*base)%MOD;
        }
        for(int i=0;i<m;i++){
            patHash = (patHash*base + needle[i])%MOD;
            textHash = (textHash*base + haystack[i])%MOD;
        }
        for(int i=0;i<=n-m;i++){
            if(patHash == textHash){
                if(haystack.substr(i,m)==needle) return i;
            }

            textHash = (base*(textHash - h*haystack[i]) + haystack[i+m])%MOD;
            if(textHash<0) textHash+=MOD;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        // Choice 1: Using Z-Algorithm
        /*
        string s = needle + "#" + haystack;
        vector<int> Z = buildZ(s);
        int p = needle.size();
        for (int i = 0; i < s.size(); i++) {
            if (Z[i] == p) return i - p - 1;
        }
        */

        // Choice 2: Using KMP
        vector<int> lps = buildLPS(needle);
        int i = 0, j = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                i++; j++;
                if(j == needle.size()) return i - j;
            } else {
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }

        // Choice 3: Simple built-in find
        // int ans = haystack.find(needle);
        // if(ans!=string::npos) return ans;

        // Choice 4: String matching using Rolling Hash
        int ans = RollingHashSearch(haystack, needle);
        if(ans!=-1) return ans;

        return -1;
    }
};