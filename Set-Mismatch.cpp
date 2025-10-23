class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>count;
        int dup,miss;

        for(int number=0;number<n;number++){
            count[nums[number]]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==2){
                dup=i;
            }
            else if(count[i]==0){
                miss=i;
            }
        }
        return {dup,miss};


        
    }
};