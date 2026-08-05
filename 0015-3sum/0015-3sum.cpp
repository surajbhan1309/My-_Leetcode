class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                long long sum=nums[left]+nums[i]+nums[right];
                if(sum==0){
                    s.insert({nums[left],nums[i],nums[right]});
                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto &x:s){
            ans.push_back(x);
        }
        return ans;
        
    }
};