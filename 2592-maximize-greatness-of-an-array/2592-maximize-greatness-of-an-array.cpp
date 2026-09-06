class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[j]>nums[i]){
                i++;
                count++;
            }
            j++;
        }
        return count;

    }
};