class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        long long count = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            while (!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }
            
            count += minHeap.size();
            
            minHeap.push(end);
        }
        
        return count;
    }
};
