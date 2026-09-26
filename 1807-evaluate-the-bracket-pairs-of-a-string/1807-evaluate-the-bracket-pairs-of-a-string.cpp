class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &x:knowledge){
            mp[x[0]]=x[1];
        }
        string key;
        string ans;
        bool flag=false;
        for(auto &c:s){
            if(c=='('){
                flag=true;
            }
            else if(c==')'){
                if(mp.count(key)){
                    ans+=mp[key];
                }
                else{
                    ans.push_back('?');
                }
                flag=false;
                key.clear();
            }
            else if(flag){
                key.push_back(c);
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};