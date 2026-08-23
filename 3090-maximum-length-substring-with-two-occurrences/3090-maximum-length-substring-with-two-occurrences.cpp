class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> frequency(26, 0);
        int left = 0;
        int answer = 0;

        // Expand the window one character at a time.
        for (int right = 0; right < s.size(); right++) {
            frequency[s[right] - 'a']++;

            // Remove characters from the left until every count is at most two.
            while (frequency[s[right] - 'a'] > 2) {
                frequency[s[left] - 'a']--;
                left++;
            }

            // Update the longest valid window.
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
