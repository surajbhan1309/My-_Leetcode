class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &w : words) mp[w]++;

        vector<pair<string,int>> v;
        for(auto &p : mp) v.push_back({p.first, p.second});

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first; // lex smaller
            return a.second > b.second; // higher freq first
        });

        vector<string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};