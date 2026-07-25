class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }

    int mergesort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int count = 0;
        
        count += mergesort(nums, low, mid);
        count += mergesort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high); // 1. Count pairs first
        merge(nums, low, mid, high);               // 2. Then sort/merge
        
        return count;
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;
        
        for (int left = low; left <= mid; left++) {
            // Use long long casting to prevent integer overflow errors
            while (right <= high && (long long)nums[left] > 2 * (long long)nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Standard merge sort operation
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
};
