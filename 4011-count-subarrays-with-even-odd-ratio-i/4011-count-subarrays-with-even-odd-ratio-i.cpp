class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int even=0;
            int odd=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    even++;
                }
                else{
                    odd++;
                }
                if(odd>0 && even*b <= odd*a){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};