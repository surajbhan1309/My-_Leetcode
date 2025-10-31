class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minheap;
        //for first k elements we will simply make a min heap
        for(auto &num:nums){
            minheap.push(num);
            if(minheap.size()>k) minheap.pop();
        }
        return minheap.top();
      
    }
};