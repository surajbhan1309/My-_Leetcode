#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& path, int start) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                break; // Prune the search space
            path.push_back(candidates[i]);
            // not i+1 because we can reuse same element
            backtrack(candidates, target - candidates[i], result, path, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end()); // Optional: for efficient pruning
        backtrack(candidates, target, result, path, 0);
        return result;
    }
};
