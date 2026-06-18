class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n/2];

        //second Approach Moore's Voting Algorithm
        int count=1;
        int element=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==element) count++;
            else if(count==0){
                element=nums[i];
                count=1;
            }
            else{
                count--;
            }
        }
        return element;
    }
};