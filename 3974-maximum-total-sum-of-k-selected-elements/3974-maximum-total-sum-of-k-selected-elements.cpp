class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum=0;
        int i=0;
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        while(i<n){
            sum+=(1LL*nums[i]*mul);
            i++;
            k--;
            mul--;
            if(k==0) break;
            if(mul==0) break;
        }
        if(i<n && k>0){
            for(int j=i;j<n;j++){
                sum+=nums[j];
                k--;
                if(k==0) break;
            }
        }
        return sum;
    }
};