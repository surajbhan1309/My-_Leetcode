class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //in n/3 majority max 2 can be major 
        //further like for n/4 is 3 and n/5 is 4 and so on
        int n=nums.size();
        int count1=0,count2=0;
        int maj1=0,maj2=1;
         // different initial values
        
        // Step 1: Find candidates
        for(int num:nums){
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

        // Step 2: Verify candidates
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