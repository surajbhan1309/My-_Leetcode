class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(map[nums[i]]==1){
                sum+=nums[i];
            }
        }
        return sum;
        
    }
};