class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mul=k;
        while(true){
            if(find(nums.begin(),nums.end(),mul)==nums.end()){
                return mul;
            }
            mul+=k;
        }
    }
};