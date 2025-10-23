// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int count =0;
//         int n = s.size()-1;

//         while(n>=0){
//             if(s[n]!=' '){
//                 count++;
//                 n--;
//             }
//             else if(s[n]== ' ' && count == 0){
//                 n--;
//             }
//             else{
//                 break;
//             }
            
//         }
//         return count;
//     }
// };
class Solution {
public:
    int lengthOfLastWord(string s) {
        int tot = 0; bool st = false;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(isalpha(s[i]))
            {
                st = true;
                ++tot;
            }
            else{
                if(st)
                {
                    return tot;
                }
            }
        }
        return tot;
    }
};