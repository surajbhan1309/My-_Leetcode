class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int maxsum=sum;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum=sum-cardPoints[k-i-1]+cardPoints[n-i-1];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
        
    }
};