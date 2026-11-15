class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int distancevalue=0;
        for(int val:arr1){
            auto it=lower_bound(arr2.begin(),arr2.end(),val);
            bool isfar=true;;
            if(it!=arr2.end() && abs(*it-val)<=d){
                isfar=false;
            }
            else if(it!=arr2.begin() && abs(*prev(it)-val)<=d){
                isfar=false;
            }
            if(isfar){
                distancevalue++;
            }
        }
        return distancevalue;
    }
};