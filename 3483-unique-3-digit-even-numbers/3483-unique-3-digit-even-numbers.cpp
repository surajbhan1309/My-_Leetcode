class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> nums;
        int n = digits.size();
        
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue;
            
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && i != k && j != k && digits[k] % 2 == 0) {
                        nums.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                    }
                }
            }
        }
        
        return nums.size();
    }
};