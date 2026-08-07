class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 || numRows>=n){
            return s;
        }
        bool down=false;
        vector<string>ans(numRows);
        int curr_row=0;
        for(char c:s){
            ans[curr_row]+=c;
            if(curr_row==0||curr_row==numRows-1){
                down=!down;
            }
            if(down) curr_row++;
            else curr_row--;
        }
        string str;
        for(auto x:ans){
            str+=x;
        }
        return str;
    }
};