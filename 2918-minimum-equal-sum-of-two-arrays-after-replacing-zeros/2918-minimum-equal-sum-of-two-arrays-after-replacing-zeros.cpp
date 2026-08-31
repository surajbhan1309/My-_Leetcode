class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0;
        long long c1=0,c2=0;
        for(auto &x:nums1){
            if(x==0) c1++;
            else sum1+=x;
        }
        for(auto &x:nums2){
            if(x==0) c2++;
            else sum2+=x;
        }
        long long tsum1=sum1+c1;
        long long tsum2=sum2+c2;
        if(c1==0 && tsum1<tsum2) return -1;
        if(c2==0 && tsum2<tsum1) return -1;

        return max(tsum1,tsum2);
    }
};