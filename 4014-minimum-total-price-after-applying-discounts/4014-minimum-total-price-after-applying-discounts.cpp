class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int n=prices.size();
        int m=discounts.size();
        double sum=0;
        int i=0,j=0;
        while(i<n && j<m){
            sum+=(prices[i]*(100-discounts[j]))/100.0;
            i++;
            j++;
        }
        if(m<n){
            for(int k=i;k<n;k++){
                sum+=prices[k];
            }
        }
        return sum;
        
    }
};