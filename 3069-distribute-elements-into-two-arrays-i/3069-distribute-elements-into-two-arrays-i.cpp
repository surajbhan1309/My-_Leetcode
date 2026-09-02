class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>n1;
        vector<int>n2;
        int n=nums.size();
        n1.push_back(nums[0]);
        n2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(n1.back()>n2.back()){
                n1.push_back(nums[i]);
            }
            else n2.push_back(nums[i]);
        }
        vector<int>ans;
        for(auto &x:n1){
            ans.push_back(x);
        }
        for(auto &x:n2){
            ans.push_back(x);
        }
        return ans;
    }
};