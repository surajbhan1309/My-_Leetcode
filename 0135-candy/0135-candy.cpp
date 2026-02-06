class Solution {
public:
    int candy(vector<int>& ratings) {
        //2nd Approach peak and dip 
        int n=ratings.size();
        int candy=n;
        int i=1;

        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak=0;
            while(ratings[i]>ratings[i-1]){
                i++;
                peak++;
                candy+=peak;
                if(i==n){
                    return candy;
                }
            }
            int dip=0;
            while(i<n && ratings[i]<ratings[i-1]){
                i++;
                dip++;
                candy+=dip;
            }
            candy-=min(peak,dip);  
        }
        return candy;
        
    }
};