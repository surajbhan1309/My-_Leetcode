class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort in dsecending order of no of units per box
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) { return a[1] > b[1]; });

        int maxUnits = 0;
        
        for (auto &x : boxTypes) {
            if (x[0] <= truckSize) {
                truckSize -= x[0];
                maxUnits += x[0] * x[1];
            } else {
                maxUnits += x[1] * truckSize;
                break;
            }
        }
        return maxUnits;
    }
};
