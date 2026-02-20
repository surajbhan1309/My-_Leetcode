
class DisjointSet {
    vector<int> parent, rank;

    public:
    // Constructor
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int findPar(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>emailtoidx;

        //step1:merge accounts using common email;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(emailtoidx.find(email)==emailtoidx.end()){
                    emailtoidx[email]=i;
                }
                else{
                    ds.unionByRank(i,emailtoidx[email]);
                }
            }
        }
        //step2:group emails by ultimate parent
        vector<vector<string>>merged(n);
        for(auto &it:emailtoidx){
            string email=it.first;
            int index=it.second;

            int parent=ds.findPar(index);
            merged[parent].push_back(email);
        }
        //step3:Prepare Final ans
        vector<vector<string>>result;
        for(int i=0;i<n;i++){
            if(merged[i].empty()) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);

            for(auto &email:merged[i]){
                temp.push_back(email);
            }
            result.push_back(temp);
        }
        return result;
    }
};

// Approach :

// Map each email to an account index

// Use a hash map um[email] = accountIndex.
// If an email already exists in the map → merge current account with the one already holding that email using DSU.

// Group emails by parent account

// For each email in the map, find its ultimate parent using findPar().
// Store emails under that parent’s bucket.

// Build final merged accounts

// For each parent account:
// Take the account name (from original input).
// Collect and sort all emails belonging to that group.
// Form the merged account [Name, sortedEmails...].

// Return the merged list.
