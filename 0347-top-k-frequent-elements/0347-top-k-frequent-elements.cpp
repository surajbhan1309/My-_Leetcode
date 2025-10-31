class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>Vmap(n);
        for(auto &x:nums){
            Vmap[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(auto &p:Vmap){
            minheap.push({p.second,p.first});
            if(minheap.size()>k) minheap.pop();
        }
        vector<int>ans;
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;



        
    }
};