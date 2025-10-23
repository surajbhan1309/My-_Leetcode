class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        for(auto &x:order){
            if(find(friends.begin(),friends.end(),x)!=friends.end()){
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};