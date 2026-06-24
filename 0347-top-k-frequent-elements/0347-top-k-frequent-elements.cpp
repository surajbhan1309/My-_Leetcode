class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int>ans;
//         int n=nums.size();
//         unordered_map<int,int>mp;
//         for(auto &x:nums){
//             mp[x]++;
//         }
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
//         for(auto &x:mp){
//             minheap.push({x.second,x.first});
//             if(minheap.size()>k) minheap.pop();
//         }
//         while(!minheap.empty()){
//             ans.push_back(minheap.top().second);
//             minheap.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };