class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;

        int m = (l + r) / 2;
        int cnt = 0;

        cnt += mergeSort(nums, l, m);
        cnt += mergeSort(nums, m+1, r);
        cnt += countCross(nums, l, m, r);
        merge(nums, l, m, r);

        return cnt;
    }

    int countCross(vector<int>& nums, int l, int m, int r) {
        int cnt = 0;
        int j = m + 1;

        for(int i = l; i <= m; i++) {
            while(j <= r && (long long)nums[i] > 2LL * nums[j])
                j++;
            cnt += (j - (m + 1));
        }
        return cnt;
        // (m+1) = starting index of right half
        // j stops where condition breaks

        // So:
        // 👉 number of valid elements = j - (m+1)
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m+1;

        while(i <= m && j <= r) {
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= m) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);

        for(int k = l; k <= r; k++) nums[k] = temp[k - l];
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};