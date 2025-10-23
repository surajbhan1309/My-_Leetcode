class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxi=0;
        while(l<r){
            int lh=height[l];
            int rh=height[r];
            int min_h=min(lh,rh);
            maxi=max(maxi,min_h*(r-l));
            if(lh<rh){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};