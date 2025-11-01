class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        unordered_map<char,int>freq;
        for(char &x:tasks){
            freq[x]++;
        }
        int time=0;
        priority_queue<int>maxheap;
        for(auto &x:freq){
            maxheap.push(x.second);
        }
        while(!maxheap.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!maxheap.empty()){
                    temp.push_back(maxheap.top()-1);
                    maxheap.pop();
                }
            }
            for(int &frequency:temp){
                if(frequency>0){
                    maxheap.push(frequency);
                }
            }
            if(maxheap.empty()){
                time+=temp.size();
            }
            else{
                time+=(n+1);
            }

        }
        return time;
        
    }
};