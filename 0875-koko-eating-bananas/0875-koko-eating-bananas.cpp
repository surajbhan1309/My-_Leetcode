class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<high){
            int mid=low+(high-low)/2;
            if(Ispossible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
    bool Ispossible(int mid,vector<int>&piles,int h){
        int totalhours=0;
        for(auto &pile:piles){
            totalhours+=(pile+mid-1)/mid;
        }
        return totalhours<=h;
    }
};