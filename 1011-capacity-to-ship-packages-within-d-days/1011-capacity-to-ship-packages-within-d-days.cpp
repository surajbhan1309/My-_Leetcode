class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight=-1,totalWeight=0;
        for(int weight:weights){
            maxWeight=max(maxWeight,weight);
            totalWeight=totalWeight+weight;
        }

        int low=maxWeight;
        int high=totalWeight;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int noofdays=finddays(weights,mid);
            if(noofdays<=days){
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
        int day=1;
        for(int i=0;i<n;i++){
            if(load+weights[i]>capacity){
                day++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }
};