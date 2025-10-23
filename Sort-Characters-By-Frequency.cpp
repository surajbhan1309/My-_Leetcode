class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        priority_queue<pair<int,char>>maxheap;
        for(auto &[ch,f]:freq){
            maxheap.push({f,ch});
        }
        string result;
        while(!maxheap.empty()){
            auto[count,ch]=maxheap.top();
            maxheap.pop();
            result+=string(count,ch);
        }
        return result;
        
    }
};