class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int s=0;
        for(auto &g:gain){
            s+=g;
            maxi=max(maxi,s);
        }
        return maxi;
        
    }
};