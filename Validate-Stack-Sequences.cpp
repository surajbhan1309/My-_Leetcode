class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>s;
        int i=0,j=0;
        s.push(pushed[0]);
        while(i<pushed.size()){
            if(!s.empty()&&popped[j]==s.top()){
                s.pop();
                j++;
            }
            else{
                s.push(pushed[i]);
                i++;
            }
        }
        while(j<popped.size()){
            if(!s.empty()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
            else{
                return false;
            }
        }
        return true;

    }
};