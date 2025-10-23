class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> st;

   	sort(arr.begin(), arr.end());
	   
	for (int i=0; i<arr.size()-2; i++) {
		int left = i+1;
		int right = arr.size()-1;

		while (left < right) {
			int sum = arr[i] + arr[left] + arr[right];
			if (sum == 0) {
				vector<int> temp = {arr[i], arr[left], arr[right]};
				sort(temp.begin(), temp.end());
				st.insert(temp);
				left++;
				right--;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				left++;
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
   	return ans;
        
    }
};