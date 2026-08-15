class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                // closing>opening
                if (st.size() == 0) {
                    return false;
                }

                // closing char
                if (st.top() == '(' && s[i] == ')' ||
                    st.top() == '[' && s[i] == ']' ||
                    st.top() == '{' && s[i] == '}') {
                    st.pop();
                } else {
                    // no matching character
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
// closing>opening({}])]]]
// closing<opening [({})