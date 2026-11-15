class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD=1e9+7;
        int count=0;
        int prefix_sum=0;
        int odd_count=0;
        int even_count=1;
        
        for(int num:arr){
            prefix_sum+=num;
            if(prefix_sum%2==0){
                count=(count+odd_count)%MOD;
                even_count++;
            }
            else{
                count=(count+even_count)%MOD;
                odd_count++;
            }
        }
        return count;
    }

};