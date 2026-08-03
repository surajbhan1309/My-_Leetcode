class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ns=newInterval[0];
        int ne=newInterval[1];
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<ns){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=ne){
            ns=min(intervals[i][0],ns);
            ne=max(intervals[i][1],ne);
            i++;
        }
        ans.push_back({ns,ne});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;

    }
};