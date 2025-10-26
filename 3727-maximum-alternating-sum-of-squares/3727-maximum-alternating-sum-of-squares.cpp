class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a ,int b){
            return abs(a)<abs(b);
        });
        long long ans=0;
        int left=0,right=nums.size()-1;
        bool flag=true;
        while(left<=right){
            if(flag){
                ans+=1LL*nums[right]*nums[right];
                right--;
            }
            else{
                ans-=1LL*nums[left]*nums[left];
                left++;
            }
            flag=!flag;
        }
        return ans;
        
        
    }
};