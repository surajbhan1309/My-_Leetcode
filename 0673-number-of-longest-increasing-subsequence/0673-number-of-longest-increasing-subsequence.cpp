class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>len(n,1),count(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){

                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        count[i]=count[j];
                    }
                    else if(len[j]+1 == len[i]){
                        len[i]=len[j]+1;
                        count[i]+=count[j];
                    }
                    
                }
            }
            maxlen=max(maxlen,len[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(len[i]== maxlen){
                ans+=count[i];
            }
        }
        return ans;

    }
};