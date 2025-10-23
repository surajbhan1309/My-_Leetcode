class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n/2];

        //second Approach Moore's Voting Algorithm
        int count=1;
        int maj=nums[0];
        int size=nums.size();
        for(int i=1;i<size;i++)
        {
            if(nums[i]==maj)
                count++;
            else{
                count--;
            }
            if(count<=0)
            {
                maj=nums[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==maj)
                count++;
        }
        if(count>(size/2))
            return maj;
        return -1;
    }
};