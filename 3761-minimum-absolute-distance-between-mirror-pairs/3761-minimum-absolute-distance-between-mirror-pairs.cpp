class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int mini=INT_MAX;
        unordered_map<int,int>index;
        int n=nums.size();
        for(int j=0;j<n;j++){
            int curr=nums[j];
            if(index.count(curr)){
                int i=index[curr];
                int dist=j-i;
                if(dist<mini){
                    mini=dist;
                }
            }
            
        int rev=reversenum(curr);
        index[rev]=j;
            
        }
        

        if(mini==INT_MAX) return -1;
        return mini;
           
    }
    int reversenum(int num){
        int reversed=0;
        while(num>0){
            reversed=reversed*10+num%10;
            num/=10;
        }
        return reversed;
    }
};