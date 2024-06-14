class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (auto &c: s) {
            switch(c) {
                case '(':
                case '[':
                case '{':
                    stck.push(c);
                    break;
                case ')':
                    if (stck.empty()) {
                        return false;
                    }
                    if (stck.top() == '(') {
                        stck.pop();
                        break;
                    }
                    else {
                        return false;
                    }
                case ']':
                    if (stck.empty()) {
                        return false;
                    }
                    if (stck.top() == '[') {
                        stck.pop();
                        break;
                    }
                    else {
                        return false;
                    }
                case '}':
                    if (stck.empty()) {
                        return false;
                    }
                    if (stck.top() == '{') {
                        stck.pop();
                        break;
                    }
                    else {
                        return false;
                    }
            }
        }
        return stck.empty();
    }
};