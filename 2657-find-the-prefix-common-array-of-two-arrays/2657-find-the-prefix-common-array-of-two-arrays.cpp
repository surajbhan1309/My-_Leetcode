class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int n=A.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j>=0;j--) mp[A[j]]++;
            for(int k=i;k>=0;k--) mp[B[k]]--;
            int count=0;
            for(auto &x:mp){
                if(x.second==0){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};