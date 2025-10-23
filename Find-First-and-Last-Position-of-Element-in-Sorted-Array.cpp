class Solution {
public:
    int firstOcc(vector<int>& arr, int n, int key) {
        int s = 0, e = n-1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                e = mid - 1; // go left to find first occurrence
            }
            else if (key > arr[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int n, int key) {
        int s = 0, e = n-1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                s = mid + 1; // go right to find last occurrence
            }
            else if (key > arr[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOcc(nums, n, target);
        int last = lastOcc(nums, n, target);
        return {first, last}; // ✅ directly returning vector
    }
};
