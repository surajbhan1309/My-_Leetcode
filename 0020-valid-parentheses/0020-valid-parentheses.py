class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c in ('(', '{', '['):
                st.append(c)
            else:
                if st:
                    top = st[-1]
                    if (c == ')' and top == '(') or (c == ']' and top == '[') or (c == '}' and top == '{'):
                        st.pop()
                    else:
                        return False
                else:
                    return False
        return len(st) == 0
