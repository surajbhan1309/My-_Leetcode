class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                str += s[i];
            } else if (!str.empty()) {
                st.push(str);
                str = "";
            }
        }
        // Last word
        if (!str.empty()) {
            st.push(str);
        }

        string reversed;
        while (!st.empty()) {
            reversed += st.top();
            st.pop();
            if (!st.empty()) {
                reversed += ' ';
            }
        }

        return reversed;
    }
};
