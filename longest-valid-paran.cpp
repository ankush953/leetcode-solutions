// https://leetcode.com/problems/longest-valid-parentheses/
// space O(n)
// time O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int n = s.length();
        int i;
        for (i=0;i<n;i++) {
            if (s[i]=='(') {
                st.push(i);
            }
            else {
                if (st.top() == -1 || s[st.top()] == ')') {
                    st.push(i);
                }
                else if (s[st.top()]=='(') {
                    st.pop();
                }
            }
        }
        int ans = 0;
        int curr = n;
        while (!st.empty()) {
            ans = max(ans, curr-st.top()-1);
            curr = st.top();
            st.pop();
        }
        return ans;
    }
};