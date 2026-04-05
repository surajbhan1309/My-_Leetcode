class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size() & 1) return false;
        unordered_map<char,int>Vmap;
        for(char c:moves){
            Vmap[c]++;
        }
        return Vmap['U'] == Vmap['D'] && Vmap['L'] == Vmap['R'];

        
    }
};