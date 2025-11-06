class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n) return -1;

        int low=INT_MAX,high=INT_MIN;
        for(int day:bloomDay){
            low=min(low,day);
            high=max(high,day);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(isAns(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }bool isAns(vector<int>&bloomDay,int m,int k,int day){
        int n=bloomDay.size();
        int adjacent_flowers=0;
        int bouquets_made=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                adjacent_flowers++;
                if(adjacent_flowers==k){
                    bouquets_made++;
                    adjacent_flowers=0;
                }
            }
        else{
            adjacent_flowers=0;
        }
        }
        return bouquets_made>=m;
    }
    
};