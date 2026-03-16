class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> m; 
        for(int n : nums){
            m[n]++; 
        }
        for(int n : nums){
            if(n%2 == 0 && m[n] == 1) return n; 
        }
        return -1; 
    }
};