class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        auto M=make_pair(nums,queries);
        const long long int MOD=1e9+7;
        int n=queries.size();
        for(auto &v:queries){
            int li=v[0];
            int ri=v[1];
            int ki=v[2];
            int vi=v[3];
            long long int  idx=li;
            while(idx<=ri){
                nums[idx] = (1LL * nums[idx] * vi) % MOD;

                idx+=ki;
            }
        }
        int result=0;
        for(int x:nums){
            result^=x;
        }
    return result;
    }
};