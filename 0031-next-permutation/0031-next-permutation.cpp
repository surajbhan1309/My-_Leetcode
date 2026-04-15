class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step1:Find the point where where numbers getting decreasing
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        
        //Step2:Find the the number which is just greater than in the right side and swap with them

        if(i>=0){
            int j=nums.size()-1;
            while(j>=0 && nums[j]<=nums[j+1]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        
        //Step3:After swapping ,reverse the right side of number which i found in step 1 and also swap it 
        reverse(nums.begin()+i+1,nums.end());
    }
    
    
};