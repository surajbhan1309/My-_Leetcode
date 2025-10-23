class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp=s;
        if(s.size()!=goal.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            bool flag=true;
            for(int j=0;j<goal.size();j++){
                if(temp[j]!=goal[j]){
                    flag=false;
                    break;

                }
                
            }
            if(flag){
                return true;
            }
            int t=s[i];
            temp.erase(temp.begin());
            temp+=t;
        }
        return false;
            
    }
};