class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        unordered_map<string,int>Vmap;
        int ans=1;
        for(string &w:words){
            Vmap[w]=1;
            for(int i=0;i<w.size();i++){
                string pred=w.substr(0,i)+w.substr(i+1);
                if(Vmap.count(pred)){
                    Vmap[w]=max(Vmap[w],Vmap[pred]+1);
                }
            }
            ans=max(ans,Vmap[w]);

        }
        return ans;

    }
};