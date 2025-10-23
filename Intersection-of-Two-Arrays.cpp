class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>unique(nums1.begin(),nums1.end());
        unordered_set<int>ans;
        for(int x:nums2){
            if(unique.find(x)!=unique.end()){
                ans.insert(x);
            }
        }
        return vector<int>(ans.begin(),ans.end());
        
    }
};