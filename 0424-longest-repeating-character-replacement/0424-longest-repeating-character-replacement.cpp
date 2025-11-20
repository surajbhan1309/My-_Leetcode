class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, right = 0;
        int maxFreq = 0;
        int ans = 0;
        int n = s.size();
        for (right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            while (maxFreq+k<(right-left+1)) {
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
