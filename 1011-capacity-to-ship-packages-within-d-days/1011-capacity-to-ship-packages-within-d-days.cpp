class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxW=-1;
        int totalW=0;
        for(auto &w:weights){
            maxW=max(maxW,w);
            totalW=totalW+w;
        }
        int low=maxW;
        int high=totalW;
        while(low<=high){
            int mid=low+(high-low)/2;
            int no_of_days=finddays(weights,mid);
            if(no_of_days<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
    int finddays(vector<int>&weights,int capacity){
        int n=weights.size();
        int load=0;
        int days=1;
        for(int i=0;i<n;i++){
            if(load+weights[i]>capacity){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
};