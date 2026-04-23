class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>arr(n,0);

        unordered_map<int,long long>indexsum;
        unordered_map<int,long long>indexcount;

        //left to right
        for(int i=0;i<n;i++){
            long long freq=indexcount[nums[i]];
            long long sum=indexsum[nums[i]];

            arr[i]+=freq*i-sum;

            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;
        }
        indexsum.clear();
        indexcount.clear();

        //right to left
        for(int i=n-1;i>=0;i--){
            long long freq=indexcount[nums[i]];
            long long sum=indexsum[nums[i]];

            arr[i]+=sum-freq*i;

            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;

        }
        return arr;


    }
};