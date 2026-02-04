class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(caneat(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
    bool caneat(int k,vector<int>&piles,int h){
        long long hours=0;
        for(auto & pile:piles){
            hours+=(pile+k-1)/k;
        }
        return hours<=h;
    }
};
