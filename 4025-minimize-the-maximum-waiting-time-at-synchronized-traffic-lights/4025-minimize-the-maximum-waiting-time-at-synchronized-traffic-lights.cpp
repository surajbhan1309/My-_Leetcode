class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxe=*max_element(lights.begin(),lights.end());
        int n=arrivalTime.size();
        int waitingtime=0;
        for(int i=0;i<n;i++){
            int r=arrivalTime[i]%period;
            if(r>=maxe) waitingtime=max(waitingtime,period-r);
        }
        return waitingtime;
    }
};