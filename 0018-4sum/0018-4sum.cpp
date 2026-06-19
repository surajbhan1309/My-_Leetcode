class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        
    }
};