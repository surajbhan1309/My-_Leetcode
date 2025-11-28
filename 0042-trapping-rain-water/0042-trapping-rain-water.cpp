class Solution {
public:
    //Two pointer Approach
    int trap(vector<int>& height) {
        int n=height.size();
       int left=0,right=n-1;
       int ans=0;
       int lmax=0,rmax=0;
       while(left<=right){
            lmax=max(lmax,height[left]);
            rmax=max(rmax,height[right]);
            if(lmax<rmax){
                ans+=(lmax-height[left]);
                left++;
            }
            else{
                ans+=(rmax-height[right]);
                right--;
            }
       }
       return ans;
        
    }
};