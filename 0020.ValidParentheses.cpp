#include <bits/stdc++.h>
using namespace std;

/* Sol: Decrease the match prefix */
/* Time complexity: O(n^2) */

class Solution {
public:
    bool validParenthese(string s) {
        if (s.length() % 2 != 0) return false;

        stack<char> st;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (!st.empty()) {
                    if (c == ')' && st.top() == '(') st.pop();
                    else if (c == ']' && st.top() == '[') st.pop();
                    else if (c == '}' && st.top() == '{') st.pop();
                    else return false;
                } else return false;
            }
        }

        return st.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string str = "()[]{}";
    cout << (s.validParenthese(str) ? "true" : "false") << endl;
    return 0;
}
