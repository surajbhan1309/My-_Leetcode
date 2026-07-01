class Solution {
private:
    vector<int> computeLPSArray(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool kmpSearch(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();
        if (m == 0) return true;
        if (n == 0) return false;

        vector<int> lps = computeLPSArray(pattern);
        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            if (j == m) {
                return true; // Match found
            } 
            else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();
        
        // Calculate the base number of repetitions needed
        int minReps = (lenB + lenA - 1) / lenA;
        
        // Build the text for minimum repetitions
        string repeatedA = "";
        for (int i = 0; i < minReps; i++) {
            repeatedA += a;
        }
        
        // Check 1: Find b in a * minReps
        if (kmpSearch(repeatedA, b)) {
            return minReps;
        }
        
        // Check 2: Find b in a * (minReps + 1)
        repeatedA += a;
        if (kmpSearch(repeatedA, b)) {
            return minReps + 1;
        }
        
        return -1;
    }
};
