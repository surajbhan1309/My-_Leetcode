class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for (auto &word : words) {
            int sum = 0;
            for (auto ch : word) {
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            ans += 'a' + 26 - sum - 1;
        }

        return ans;
    }
};

// Approach
// Initialize an empty string ans to store the result.
// For each word:
// Iterate through its characters and sum their weights using the weights array.
// Take sum % 26.
// Convert the value to a character using reverse mapping:
// 'a' + 26 - sum - 1
// Append this character to the result string.
// Return the final concatenated string.