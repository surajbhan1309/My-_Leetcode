class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       set<vector<int>>st;
       int n=nums.size();
       for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum==0){
                    st.insert({nums[left],nums[right],nums[i]});
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
       
       vector<vector<int>>ans(st.begin(),st.end());
       for(auto x:ans){
            sort(x.begin(),x.end());
       }
       return ans; 
    }
};