class Solution {
public:
    string frequencySort(string s) {
        map<char,int>Vmap;
        for(auto &c:s){
            Vmap[c]++;
        }
        priority_queue<pair<int,char>>maxheap;
        for(auto &[c,freq]:Vmap){
            maxheap.push({freq,c});
        }
        string ans;
        while(!maxheap.empty()){
            auto [freq,c]=maxheap.top();
            maxheap.pop();
            ans+=string(freq,c);

        }
        return ans;

        
    }
};