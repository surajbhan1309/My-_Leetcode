class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int maj1=nums[0],maj2=nums[0];
        int count1=0,count2=0;
        for(auto &num:nums){
            if(num==maj1) count1++;
            else if(num==maj2) count2++;
            else if(count1==0){
                maj1=num;
                count1=1;
            }
            else if(count2==0){
                maj2=num;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c1=0,c2=0;
        for(int num:nums){
            if(num==maj1) c1++;
            else if(num==maj2) c2++;
        }
        vector<int>ans;
        if(c1>(n/3)) ans.push_back(maj1);
        if(c2>(n/3)) ans.push_back(maj2);
        return ans;
    }
};