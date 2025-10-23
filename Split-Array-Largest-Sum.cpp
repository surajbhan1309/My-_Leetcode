class Solution {
public:
    bool isPossible(vector<int> arr, int n, int k, int mid) {
    int subarrayCount = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            subarrayCount++;
            if (subarrayCount > k || arr[i] > mid) {
                return false;
            }
            sum = arr[i];
        }
        if (subarrayCount > k) {
            return false;
        }
    }
    return true;
}

int splitArray(vector<int> arr,int k) {
    int n=arr.size();
    int s = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int e = sum;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
};