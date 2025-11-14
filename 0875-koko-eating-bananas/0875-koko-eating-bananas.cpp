class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MAX;
        
        while(left<right){
            int mid=left+(right-left)/2;
            int hoursSpent=0;

            for (int i = 0; i < piles.size(); i++) {
                hoursSpent += (piles[i] + mid - 1) / mid;
            }

            if (hoursSpent<=h){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left; 
    }
};
