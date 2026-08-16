class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int element=nums[0];
        int count=0;

        for(auto &num:nums){
            if(num==element){
                count++;
            }
            else if(count==0){
                element=num;
                count=1;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int x:nums){
            if(x==element){
                count++;
            }
        }
        if(count>n/2){
            return element;
        }
        return -1;
    }
};