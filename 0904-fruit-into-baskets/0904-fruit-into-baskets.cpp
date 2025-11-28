class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0;
        int ans=0;
        unordered_map<int,int>Vmap;
        for(int right=0;right<n;right++){
            Vmap[fruits[right]]++;
            while(Vmap.size()>2){
                Vmap[fruits[left]]--;
                if(Vmap[fruits[left]]==0){
                    Vmap.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
    return ans;
        
    }
};