class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>Vmap;
        for(auto &x:nums){
            Vmap[x]++;
        }
        int sum=0;
        for(auto &x:Vmap){
            if(x.second%k==0){
                sum+=x.first*x.second;
            }
        }
        return sum;
        
    }
};