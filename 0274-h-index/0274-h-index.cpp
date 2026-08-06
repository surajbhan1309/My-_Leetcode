class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>indx(n+1,0);
        for(auto &c:citations){
            if(c>n){
                indx[n]++;
            }
            else{
                indx[c]++;
            }
        }
        int count=0;
        for(int i=n;i>=0;i--){
            count+=indx[i];
            if(count>=i){
                return i;
            }
        }
        return 0;

    }
};