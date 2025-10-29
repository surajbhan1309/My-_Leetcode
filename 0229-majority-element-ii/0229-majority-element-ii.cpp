class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count=nums.size()/3;
        unordered_map<int,int>map;
        vector<int>output;
        for(auto num:nums){
            map[num]++;
        }
        for(auto num:map){
            if(num.second>count){
                output.push_back(num.first);
            }
        }
        return output;
        
    }
};