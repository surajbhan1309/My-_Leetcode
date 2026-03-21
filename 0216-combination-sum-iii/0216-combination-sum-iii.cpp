class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        // total masks from 0 to (2^9 - 1)
        for (int mask = 0; mask < (1 << 9); mask++) {
            vector<int> temp;
            int sum = 0;

            for (int i = 0; i < 9; i++) {
                if (mask & (1 << i)) {
                    int num = i + 1; // numbers from 1 to 9
                    temp.push_back(num);
                    sum += num;
                }
            }

            if (temp.size() == k && sum == n) {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};