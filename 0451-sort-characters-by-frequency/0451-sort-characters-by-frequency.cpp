class Solution {
public:
    string frequencySort(string s) {
        map<char,int>f;
        for(auto &c:s){
            f[c]++;
        }
        priority_queue<pair<int,char>>maxheap;
        for(auto &x:f){
            maxheap.push({x.second,x.first});
        }
        string ans;
        while(!maxheap.empty()){
            auto [fre,ch]=maxheap.top();
            maxheap.pop();
            ans.append(fre,ch);
        }
        return ans;
    }
};