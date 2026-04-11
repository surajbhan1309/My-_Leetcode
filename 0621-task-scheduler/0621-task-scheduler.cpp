class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s=tasks.size();
        unordered_map<char,int>Vmap;
        for(auto &c:tasks){
            Vmap[c]++;
        }
        int time=0;
        priority_queue<int>maxheap;
        for(auto &c:Vmap){
            maxheap.push(c.second);
        }
        while(!maxheap.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!maxheap.empty()){
                    temp.push_back(maxheap.top()-1);
                    maxheap.pop();
                }
            }
            for(auto &f:temp){
                if(f>0){
                    maxheap.push(f);
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