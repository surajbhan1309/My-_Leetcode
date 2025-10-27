class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n=nums.size();
        long long sum=0;
        for(long long i=0;i<n;i++){
            long long smallest=nums[i];
            long long largest=nums[i];
            for(int j=i;j<n;j++){
                smallest=min(smallest,nums[j]);
                largest=max(largest,nums[j]);
                sum+=(largest-smallest);
            }
        }
        return sum;
        
    }
};