class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(auto &x:s){
            if(!s.count(x-1)){
                int length=1;
                int curr=x;
                while(s.count(curr+1)){
                    curr++;
                    length++;
                }
                longest=max(longest,length);
            }
        }
        return longest;
    }
};