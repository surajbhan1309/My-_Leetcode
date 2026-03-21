class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int mask=0;mask<(1<<n);mask++){
            vector<int>subset;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            st.insert(subset);
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;

        
    }
};