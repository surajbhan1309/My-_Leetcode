class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        int even=0,odd=0;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(nums[i]%2==0){
                ans.push_back(odd);
                even++;
            }
            else{
                odd++;
                ans.push_back(even);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};