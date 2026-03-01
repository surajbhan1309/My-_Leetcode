class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> hash;
        for(int num:nums){
            hash[num]++;
        }
        int mini=*min_element(nums.begin(),nums.end());
        int cnt=hash[mini];
        for(auto &t:hash){
            int count=t.second;
            if(count==cnt) continue;
            return {mini,t.first};
        }
        return {-1,-1};
    }
};